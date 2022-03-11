#include <fstream>
#include <filament/TransformManager.h>
#include "../event/EventList.h"
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "GltfLoader.h"
#include "../context/context.h"

namespace fwlab::loader
{
	GltfLoader::GltfLoader()
	{
		app->addEventListener(event::ANIMATE, "GltfLoader", std::bind(&GltfLoader::handleAnimate, this, std::placeholders::_1));
	}

	GltfLoader::~GltfLoader()
	{
		auto iter = loaded.begin();
		while (iter != loaded.end())
		{
			auto data = *iter;
			data->destroy();
			delete data;
			iter = loaded.erase(iter);
		}
	}

	void GltfLoader::load(
		::utils::Path path,
		std::function<void(core::Object3D*)> onLoad,
		std::function<void(float)> onProgress,
		std::function<void(std::string)> onError
	)
	{
		auto data = new LoadData();
		if (!data->load(path))
		{
			if (onError)
			{
				onError(data->getError());
			}
			return;
		}

		data->setOnLoad(onLoad);
		data->setOnProgress(onProgress);
		data->setOnError(onError);

		loading.push_back(data);
	}

	bool GltfLoader::destroyAsset(gltfio::FilamentAsset* asset)
	{
		auto iter = std::find_if(loaded.begin(), loaded.end(), [&](LoadData* data) {
			return data->getAsset() == asset;
			});
		if (iter != loaded.end())
		{
			auto data = *iter;
			data->destroy();
			delete data;
			loaded.erase(iter);
			loaded.shrink_to_fit();
			return true;
		}
		return false;
	}

	void GltfLoader::createObject3D(::utils::Entity* entity, core::Object3D* parent, LoadData* data)
	{
		auto& transformManager = app->getEngine()->getTransformManager();
		auto transformInstance = transformManager.getInstance(*entity);

		auto nameComponentManager = data->getNameComponentManager();
		auto nameComponentInstance = nameComponentManager->getInstance(*entity);

		std::string name;
		if (nameComponentInstance.isValid())
		{
			name = nameComponentManager->getName(nameComponentInstance);
		}

		parent->setName(name);
		parent->setEntity(*entity);
		auto matrix = transformManager.getTransformAccurate(transformInstance);
		parent->setMatrix(matrix);

		auto count = transformManager.getChildCount(transformInstance);
		::utils::Entity* entities = new ::utils::Entity[count];
		transformManager.getChildren(transformInstance, entities, count);

		for (auto p = entities; p < entities + count; p++)
		{
			auto child = new core::Object3D();
			createObject3D(p, child, data);
			parent->add(child);
		}
	}

	void  GltfLoader::handleAnimate(void* data)
	{
		auto iter = loading.begin();
		while (iter != loading.end())
		{
			auto data = *iter;
			auto progress = data->update();
			if (progress == 1)
			{
				auto onLoad = data->getOnLoad();
				auto onProgress = data->getOnProgress();
				if (onProgress)
				{
					onProgress(progress);
				}
				if (onLoad)
				{
					auto entity = data->getAsset()->getRoot();
					auto obj = new core::Object3D();
					createObject3D(&entity, obj, data);
					onLoad(obj);
					loaded.push_back(data);
					iter = loading.erase(iter);
				}
			}
			else
			{
				auto onProgress = data->getOnProgress();
				if (onProgress)
				{
					onProgress(progress);
				}
			}
			if (iter < loading.end())
			{
				iter++;
			}
		}
	}

	// LoadData

	bool GltfLoader::LoadData::load(::utils::Path& path)
	{
		auto engine = app->getEngine();
		this->path = path;
		type = path.getExtension() == "glb" ? Type::Binary : Type::Json;

		configuration.engine = engine;
		auto absPath = path.getAbsolutePath();
		configuration.gltfPath = absPath.c_str();
		configuration.normalizeSkinningWeights = true;
		configuration.recomputeBoundingBoxes = true;

		materialProvider = gltfio::createMaterialGenerator(engine);
		nameComponentManager = new ::utils::NameComponentManager(::utils::EntityManager::get());

		assetLoader = gltfio::AssetLoader::create({
			.engine = engine,
			.materials = materialProvider,
			.names = nameComponentManager
			});
		if (!createAssetFromFile(path))
		{
			return false;
		}

		resourceLoader = new gltfio::ResourceLoader(configuration);
		if (!resourceLoader->asyncBeginLoad(asset))
		{
			error << "cannot load resources";
			return false;
		}

		asset->releaseSourceData();

		return true;
	}

	float GltfLoader::LoadData::update()
	{
		resourceLoader->asyncUpdateLoad();
		return resourceLoader->asyncGetLoadProgress();
	}

	void GltfLoader::LoadData::destroy()
	{
		if (assetLoader)
		{
			assetLoader->destroyAsset(asset);
			gltfio::AssetLoader::destroy(&assetLoader);
		}
		if (resourceLoader)
		{
			delete resourceLoader;
		}

		delete nameComponentManager;
		if (materialProvider)
		{
			materialProvider->destroyMaterials();
		}
		delete materialProvider;
	}

	bool GltfLoader::LoadData::createAssetFromFile(::utils::Path& path)
	{
		std::ifstream in(path.c_str(), std::ifstream::ate | std::ifstream::binary);
		in.seekg(0, std::ios::end);
		auto fileSize = static_cast<long>(in.tellg());
		std::vector<uint8_t> buffer(fileSize);
		in.seekg(0, std::ios::beg);
		if (!in.read((char*)buffer.data(), fileSize))
		{
			error << "unable to read: " << path.c_str();
			return false;
		}
		in.close();
		if (type == Type::Binary)
		{
			asset = assetLoader->createAssetFromBinary(buffer.data(), buffer.size());
		}
		else
		{
			asset = assetLoader->createAssetFromJson(buffer.data(), buffer.size());
		}

		buffer.clear();
		buffer.shrink_to_fit();
		return true;
	}

	GltfLoader::Type GltfLoader::LoadData::getType() const
	{
		return type;
	}

	gltfio::ResourceConfiguration GltfLoader::LoadData::getConfiguration() const
	{
		return configuration;
	}

	gltfio::MaterialProvider* GltfLoader::LoadData::getMaterialProvider() const
	{
		return materialProvider;
	}

	::utils::NameComponentManager* GltfLoader::LoadData::getNameComponentManager() const
	{
		return nameComponentManager;
	}

	gltfio::AssetLoader* GltfLoader::LoadData::getAssetLoader() const
	{
		return assetLoader;
	}

	gltfio::FilamentAsset* GltfLoader::LoadData::getAsset() const
	{
		return asset;
	}

	gltfio::ResourceLoader* GltfLoader::LoadData::getResourceLoader() const
	{
		return resourceLoader;
	}

	std::function<void(core::Object3D*)> GltfLoader::LoadData::getOnLoad() const
	{
		return onLoad;
	}

	void GltfLoader::LoadData::setOnLoad(std::function<void(core::Object3D*)> callback)
	{
		onLoad = callback;
	}

	std::function<void(float)> GltfLoader::LoadData::getOnProgress() const
	{
		return onProgress;
	}

	void GltfLoader::LoadData::setOnProgress(std::function<void(float)> callback)
	{
		onProgress = callback;
	}

	std::function<void(std::string)> GltfLoader::LoadData::getOnError() const
	{
		return onError;
	}

	void GltfLoader::LoadData::setOnError(std::function<void(std::string)> callback)
	{
		onError = callback;
	}

	std::string GltfLoader::LoadData::getError()
	{
		return error.str();
	}
}
