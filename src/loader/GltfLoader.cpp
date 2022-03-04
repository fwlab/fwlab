#include <fstream>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "GltfLoader.h"
#include "../context/context.h"

namespace fwlab::loader
{
	GltfLoader::GltfLoader()
	{
		auto engine = app->getEngine();
		materialProvider = gltfio::createMaterialGenerator(engine);
		names = new ::utils::NameComponentManager(::utils::EntityManager::get());
		assetLoader = gltfio::AssetLoader::create({ engine, materialProvider, names });

		configuration = {};
		configuration.engine = engine;
		configuration.gltfPath = "";
		configuration.recomputeBoundingBoxes = false;
		configuration.normalizeSkinningWeights = true;

		log = new utils::Logger();
	}

	GltfLoader::~GltfLoader()
	{
		gltfio::AssetLoader::destroy(&assetLoader);
		delete names;
		delete materialProvider;
		delete log;
	}

	gltfio::FilamentAsset* GltfLoader::load(::utils::Path path)
	{
		this->destroy();
		std::ifstream in(path.c_str(), std::ifstream::ate | std::ifstream::binary);
		in.seekg(0, std::ios::end);
		auto fileSize = static_cast<long>(in.tellg());
		std::vector<uint8_t> buffer(fileSize);
		in.seekg(0, std::ios::beg);
		if (!in.read((char*)buffer.data(), fileSize))
		{
			log->error(std::string("unable to read: ") + path.c_str());
			return nullptr;
		}

		asset = assetLoader->createAssetFromJson(buffer.data(), buffer.size());
		buffer.clear();
		buffer.shrink_to_fit();

		// load resource
		auto absPath = path.getAbsolutePath();
		configuration.gltfPath = absPath.c_str();

		resourceLoader = new gltfio::ResourceLoader(configuration);
		if (!resourceLoader->asyncBeginLoad(asset))
		{
			log->error(std::string("cannot load resources"));
			return nullptr;
		}

		// asset->getAnimator();
		asset->releaseSourceData();

		return asset;
	}

	void GltfLoader::update()
	{
		if (resourceLoader)
		{
			resourceLoader->asyncUpdateLoad();
		}
	}

	bool GltfLoader::isLoaded()
	{
		return resourceLoader ? resourceLoader->asyncGetLoadProgress() == 1 : false;
	}

	bool GltfLoader::destroyAsset(gltfio::FilamentAsset* assets)
	{
		if (assetLoader)
		{
			assetLoader->destroyAsset(assets);
			return true;
		}
		return false;
	}

	void GltfLoader::destroy()
	{
		if (resourceLoader)
		{
			delete resourceLoader;
			resourceLoader = nullptr;
		}
	}
}
