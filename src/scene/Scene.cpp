#include <filament/Viewport.h>
#include <viewer/SimpleViewer.h>
#include <filamentapp/FilamentApp.h>
#include <imgui.h>
#include <filagui/ImGuiExtensions.h>
#include "../Context.h"
#include "../camera/PerspectiveCamera.h"
#include "../light/Light.h"
#include "../loader/FilameshLoader.h"
#include "resources/resources.h"
#include "Scene.h"

Context context;
PerspectiveCamera* camera;
Light* light;
Material* material;
filament::MaterialInstance* materialIndex;
FilameshLoader* loader;
Mesh* mesh;
filament::viewer::SimpleViewer* viewer;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	context = { &app, engine, view, scene };

	// 相机
	filament::Viewport viewport = view->getViewport();
	camera = new PerspectiveCamera(&context, 50, float(viewport.width) / viewport.height, 0.1, 2000);
	view->setCamera(camera->camera);

	// 光源
	light = new Light(&context);
	light->create();
	scene->addEntity(light->entity);

	// 材质
	material = new Material(&context);
	material->create(RESOURCES_AIDEFAULTMAT_DATA, RESOURCES_AIDEFAULTMAT_SIZE);
	materialIndex = material->createInstance();
	materialIndex->setParameter("baseColor", filament::RgbType::LINEAR, filament::math::float3{ 0.8 });
	materialIndex->setParameter("metallic", 1.0f);
	materialIndex->setParameter("roughness", 0.4f);
	materialIndex->setParameter("reflectance", 0.5f);

	// 模型
	loader = new FilameshLoader(&context);
	mesh = loader->load(RESOURCES_MONKEY_DATA, materialIndex);
	mesh->setTranslation({ 0, 0, -10 });
	mesh->setScaling({ 2, 2, 2 });
	scene->addEntity(mesh->entity);

	// UI
	viewer = new filament::viewer::SimpleViewer(engine, scene, view);
	viewer->setUiCallback(Scene::uiCallback);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	engine->destroy(materialIndex);
	delete material;
	delete light;
	delete camera;
	delete viewer;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	mesh->setRotation(now, filament::math::double3{ 0, 1, 0 });

	viewer->updateRootTransform();
	// viewer->populateScene(app.asset);
	viewer->applyAnimation(now);
}


void Scene::imgui(filament::Engine* engine, filament::View* view)
{
	viewer->updateUserInterface();
	FilamentApp::get().setSidebarWidth(viewer->getSidebarWidth());
}

void Scene::uiCallback()
{
	ImGui::Text("Hello, world!");
}
