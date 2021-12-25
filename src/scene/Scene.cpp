#include <imgui.h>
#include <filament/Camera.h>
#include <filagui/ImGuiExtensions.h>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "Scene.h"

using namespace gl::core;
using namespace gl::geometry;
using namespace gl::material;
using namespace gl::object;
using namespace gl::light;
using namespace gl::loader;

Context context;
Light* light;
PlaneGeometry* geometry;
StandardMaterial* material;
Mesh* plane;
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

	// 几何
	geometry = new PlaneGeometry(&context);
	geometry->create(10, 10, 10);

	// 材质
	material = new StandardMaterial(&context);
	material->create();

	// 平面
	plane = new Mesh(&context);
	plane->receiveShadows = true;
	plane->create(geometry, material);
	plane->setTranslation({ 0, -2, -10 });
	plane->setRotation(-M_PI / 2, { 1, 0, 0 });
	scene->addEntity(plane->entity);

	// 模型
	loader = new FilameshLoader(&context);
	mesh = loader->load(RESOURCES_MONKEY_DATA, material->instance);
	auto& manager = engine->getRenderableManager();
	auto instance = manager.getInstance(mesh->entity);
	manager.setCastShadows(instance, true);
	manager.setReceiveShadows(instance, true);

	mesh->setTranslation({ 0, 0, -10 });
	mesh->setScaling({ 2, 2, 2 });
	scene->addEntity(mesh->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	delete plane;
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
