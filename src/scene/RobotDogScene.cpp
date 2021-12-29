#include <iostream>
#include <fstream>
#include <vector>
#include <filament/Camera.h>
#include <filament/TransformManager.h>
#include <math/vec3.h>
#include <math/mat4.h>
#include <gltfio/AssetLoader.h>
#include <gltfio/ResourceLoader.h>
#include <utils/EntityManager.h>
#include <utils/NameComponentManager.h>
#include <utils/Path.h>
#include "RobotDogScene.h"

utils::NameComponentManager* names;
gltfio::AssetLoader* loader;
gltfio::FilamentAsset* asset;
gltfio::ResourceLoader* resourceLoader;

void RobotDogScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	// camera
	auto& camera = view->getCamera();
	//filament::TransformManager& manager = engine->getTransformManager();
	//filament::math::double3 translation = { 30, 40, 50 };
	//auto translateMatrix = filament::math::mat4::translation(translation);
	//manager.setTransform(manager.getInstance(camera.getEntity()), translateMatrix);
	camera.lookAt({ 300, 400, 500 }, { 0, 0, 0 });

	// load asset
	utils::Path filename = "assets/models/RobotDog/scene.gltf";
	if (!filename.exists())
	{
		std::cout << filename << " is not existed." << std::endl;
		return;
	}

	std::ifstream in(filename.c_str(), std::ifstream::ate || std::ifstream::binary);
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
	auto& manager = utils::EntityManager::get();
	names = new utils::NameComponentManager(manager);

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

	// add to scene
	scene->addEntities(asset->getEntities(), asset->getEntityCount());
}

void RobotDogScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	resourceLoader->asyncCancelLoad();
	loader->destroyAsset(asset);
	gltfio::AssetLoader::destroy(&loader);
}

void RobotDogScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	resourceLoader->asyncUpdateLoad();
}

void RobotDogScene::preRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer)
{

}

void RobotDogScene::postRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer)
{

}