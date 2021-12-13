#include <filament/TransformManager.h>
#include <filament/Viewport.h>
#include <filament/Skybox.h>
#include <filament/Material.h>
#include <filamentapp/Cube.h>
#include <camutils/Manipulator.h>
#include <viewer/SimpleViewer.h>
#include <utils/EntityManager.h>
#include "object/triangle.h"
#include "resources/resources.h"
#include "scene.h"

filament::Skybox* skybox;
filament::Material* mat;
Triangle* triangle;
utils::Entity camera;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	skybox = filament::Skybox::Builder()
		.color({ 0.1, 0.125, 0.25, 1.0 })
		.build(*engine);
	scene->setSkybox(skybox);
	view->setPostProcessingEnabled(false);

	filament::viewer::SimpleViewer* viewer = new filament::viewer::SimpleViewer(engine, scene, view);

	filament::TransformManager& tm = engine->getTransformManager();
	filament::Viewport viewport = view->getViewport();

	mat = filament::Material::Builder()
		.package(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE)
		.build(*engine);

	triangle = new Triangle(engine, mat);
	scene->addEntity(triangle->entity);

	camera = utils::EntityManager::get().create();
	filament::Camera* cam = engine->createCamera(camera);
	cam->setProjection(45, viewport.width / viewport.height, 0.1, 1000);
	cam->lookAt({ 10, 10, 10 }, { 0, 0, 0 });
	view->setCamera(cam);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	engine->destroy(skybox);
	engine->destroy(camera);
	engine->destroyCameraComponent(camera);
	utils::EntityManager::get().destroy(camera);
	delete triangle;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	//auto& tcm = engine->getTransformManager();
	//tcm.setTransform(tcm.getInstance(cube), filament::math::mat4f::rotation(now, filament::math::float3{ 0, 0, 1 }));
}