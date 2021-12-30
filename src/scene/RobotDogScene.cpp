#include <iostream>
#include <fstream>
#include <vector>
#include <filament/Camera.h>
#include <filament/TransformManager.h>
#include <filament/Viewport.h>
#include <math/vec3.h>
#include <math/mat4.h>
#include <gltfio/AssetLoader.h>
#include <gltfio/ResourceLoader.h>
#include <utils/EntityManager.h>
#include <utils/NameComponentManager.h>
#include <utils/Path.h>
#include "RobotDogScene.h"

utils::Entity cameraEntity;
filament::Camera* camera;
utils::NameComponentManager* names;
gltfio::AssetLoader* loader;
gltfio::FilamentAsset* asset;
gltfio::ResourceLoader* resourceLoader;

void RobotDogScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	auto& viewport = view->getViewport();
	auto& manager = engine->getTransformManager();

	//// camera
	//cameraEntity = utils::EntityManager::get().create();
	//filament::math::double3 axis = { 0, 1, 0 };
	//filament::math::mat4 rotateMatrix = filament::math::mat4::translation(M_PI, axis);
	//manager.setTransform(manager.getInstance(cameraEntity), rotateMatrix);
	//scene->addEntity(cameraEntity);

	//camera = engine->createCamera(cameraEntity);
	//camera->setProjection(50, float(viewport.width) / viewport.height, 0.1, 1000);
	//view->setCamera(camera);

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
	names = new utils::NameComponentManager(utils::EntityManager::get());

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
	auto entities = asset->getEntities();
	auto count = asset->getEntityCount();
	scene->addEntities(entities, count);

	// set transform
	filament::math::double3 translate = { 0, 0, -6 };
	auto translateMatrix = filament::math::mat4::translation(translate);
	filament::math::double3 axis = { 0, 1, 1 };
	auto rotateMatrix = filament::math::mat4::rotation(M_PI / 2, axis);
	filament::math::double3 scale = { 0.6, 0.6, 0.6 };
	auto scaleMatrix = filament::math::mat4::scaling(scale);
	auto transform = translateMatrix * scaleMatrix;

	for (int i = 0; i < count; i++)
	{
		manager.setTransform(manager.getInstance(entities[i]), transform);
	}
}

void RobotDogScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	resourceLoader->asyncCancelLoad();
	loader->destroyAsset(asset);
	gltfio::AssetLoader::destroy(&loader);
	engine->destroy(cameraEntity);
	engine->destroyCameraComponent(cameraEntity);
	utils::EntityManager::get().destroy(cameraEntity);
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