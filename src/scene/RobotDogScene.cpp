#include <iostream>
#include <fstream>
#include <vector>
#include <filament/Camera.h>
#include <filament/TransformManager.h>
#include <filament/Viewport.h>
#include <filamentapp/FilamentApp.h>
#include <math/vec3.h>
#include <math/mat4.h>
#include <gltfio/AssetLoader.h>
#include <gltfio/ResourceLoader.h>
#include <utils/EntityManager.h>
#include <utils/NameComponentManager.h>
#include <utils/Path.h>
#include <viewer/AutomationEngine.h>
#include <viewer/AutomationSpec.h>
#include <viewer/SimpleViewer.h>
#include "RobotDogScene.h"

filament::viewer::SimpleViewer* viewer;
utils::NameComponentManager* names;
gltfio::AssetLoader* loader;
gltfio::FilamentAsset* asset;
gltfio::ResourceLoader* resourceLoader;

void RobotDogScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	auto& viewport = view->getViewport();
	auto& manager = engine->getTransformManager();

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

	// set viewer
	viewer = new filament::viewer::SimpleViewer(engine, scene, view);
	viewer->getSettings().viewer.autoScaleEnabled = false;
	auto ibl = FilamentApp::get().getIBL();
	if (ibl) {
		viewer->setIndirectLight(ibl->getIndirectLight(), ibl->getSphericalHarmonics());
	}
	viewer->setUiCallback([&]() { this->uiCallback(); });
}

void RobotDogScene::uiCallback()
{

}

void RobotDogScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete viewer;
	resourceLoader->asyncCancelLoad();
	loader->destroyAsset(asset);
	gltfio::AssetLoader::destroy(&loader);
}

void RobotDogScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	resourceLoader->asyncUpdateLoad();

	// Optionally fit the model into a unit cube at the origin.
	viewer->updateRootTransform();

	// Add renderables to the scene as they become ready.
	viewer->populateScene(asset);

	viewer->applyAnimation(now);
}

void RobotDogScene::imgui(filament::Engine* engine, filament::View* view)
{
	viewer->updateUserInterface();
}

void RobotDogScene::preRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer)
{

}

void RobotDogScene::postRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer)
{

}