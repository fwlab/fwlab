#include <filament/Viewport.h>
#include <viewer/SimpleViewer.h>
#include <filamentapp/FilamentApp.h>
#include <imgui.h>
#include <filagui/ImGuiExtensions.h>
#include "../Context.h"
#include "../geometry/PlaneGeometry.h"
#include "../object/Mesh.h"
#include "../light/Light.h"
#include "../loader/FilameshLoader.h"
#include "resources/resources.h"
#include "Scene.h"

Context context;
Light* light;
Material* material;
PlaneGeometry* geometry;
Mesh* plane;
filament::MaterialInstance* materialIndex;
FilameshLoader* loader;
Mesh* mesh;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	context = { &app, engine, view, scene };

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

	// 平面
	geometry = new PlaneGeometry(&context);
	geometry->create(10, 10, 10);
	plane = new Mesh(&context);
	plane->create(geometry, material);
	plane->setTranslation({ 0, -10, 0 });
	plane->setRotation(-M_PI / 2, { 1, 0, 0 });
	scene->addEntity(plane->entity);

	// 模型
	loader = new FilameshLoader(&context);
	mesh = loader->load(RESOURCES_MONKEY_DATA, materialIndex);
	mesh->setScaling({ 2, 2, 2 });
	scene->addEntity(mesh->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	engine->destroy(materialIndex);
	delete material;
	delete geometry;
	delete light;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	mesh->setRotation(now, filament::math::double3{ 0, 1, 0 });
}

void Scene::imgui(filament::Engine* engine, filament::View* view)
{
}
