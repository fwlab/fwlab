#include <iostream>
#include <fstream>
#include <filament/LightManager.h>
#include <filament/TransformManager.h>
#include <utils/Path.h>
#include "Scene.h"
#include "../context/context.h"
#include "../geometry/PlaneGeometry.h"

namespace fwlab::scene
{
	void Scene::create()
	{
		auto engine = app->getEngine();
		auto scene = app->getScene();
		auto& entityManager = ::utils::EntityManager::get();

		// skybox
		skybox = filament::Skybox::Builder()
			.color({ 0.1, 0.125, 0.25, 1.0 })
			.showSun(true)
			.build(*engine);
		scene->setSkybox(skybox);

		// light
		lightEntity = entityManager.create();
		filament::LightManager::Builder(filament::LightManager::Type::SUN)
			.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(filament::sRGBColor(0.98f, 0.92f, 0.89f)))
			.intensity(110000)
			.sunAngularRadius(1.9f)
			.castShadows(true)
			.build(*engine, lightEntity);
		scene->addEntity(lightEntity);

		// load asset
		::utils::Path filename = "assets/models/RobotDog/scene.gltf";
		if (!filename.exists())
		{
			std::cerr << filename << " is not existed." << std::endl;
			return;
		}

		std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);
		in.seekg(0, std::ios::end);
		auto fileSize = static_cast<long>(in.tellg());
		std::vector<uint8_t> buffer(fileSize);
		in.seekg(0, std::ios::beg);
		if (!in.read((char*)buffer.data(), fileSize))
		{
			std::cerr << "unable to read " << filename << "." << std::endl;
			return;
		}

		auto materials = gltfio::createMaterialGenerator(engine);
		names = new ::utils::NameComponentManager(::utils::EntityManager::get());

		auto loader = gltfio::AssetLoader::create({ engine, materials, names });
		asset = loader->createAssetFromJson(buffer.data(), buffer.size());
		buffer.clear();
		buffer.shrink_to_fit();

		// load resource
		std::string gltfPath = filename.getAbsolutePath();
		gltfio::ResourceConfiguration configuration = {};
		configuration.engine = engine;
		configuration.gltfPath = gltfPath.c_str();
		configuration.recomputeBoundingBoxes = false;
		configuration.normalizeSkinningWeights = true;
		resourceLoader = new gltfio::ResourceLoader(configuration);
		if (!resourceLoader->asyncBeginLoad(asset))
		{
			std::cerr << "cannot load resources" << std::endl;
			return;
		}

		asset->getAnimator();
		asset->releaseSourceData();

		scene->addEntities(asset->getEntities(), asset->getEntityCount());
	}

	void Scene::cleanup()
	{
		auto engine = app->getEngine();

		resourceLoader->asyncCancelLoad();
		loader->destroyAsset(asset);
		gltfio::AssetLoader::destroy(&loader);
		delete names;

		engine->destroy(lightEntity);
	}

	void Scene::animate()
	{
		auto engine = app->getEngine();

		resourceLoader->asyncUpdateLoad();

		auto& manager = engine->getTransformManager();
		auto root = manager.getInstance(asset->getRoot());

		filament::math::float3 scale = { 0.001, 0.001, 0.001 };
		auto transform = filament::math::mat4f::scaling(scale);

		manager.setTransform(root, transform);
	}

	filament::math::mat4f Scene::fitIntoUnitCube(const filament::Aabb& bounds, float zoffset)
	{
		using namespace filament::math;
		auto minpt = bounds.min;
		auto maxpt = bounds.max;
		float maxExtent;
		maxExtent = std::max(maxpt.x - minpt.x, maxpt.y - minpt.y);
		maxExtent = std::max(maxExtent, maxpt.z - minpt.z);
		float scaleFactor = 2.0f / maxExtent;
		float3 center = (minpt + maxpt) / 2.0f;
		center.z += zoffset / scaleFactor;
		return mat4f::scaling(float3(scaleFactor)) * mat4f::translation(-center);
	}
}
