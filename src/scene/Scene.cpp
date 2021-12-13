#include <filament/Material.h>

#include "../camera/PerspectiveCamera.h"
#include "../object/Skybox.h"
#include "../object/Triangle.h"

#include "resources/resources.h"
#include "scene.h"

PerspectiveCamera* camera;
Skybox* skybox;
filament::Material* mat;
Triangle* triangle;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	// 相机
	camera = new PerspectiveCamera(engine, view);

	// 天空盒
	skybox = new Skybox(engine);
	scene->setSkybox(skybox->skybox);

	// 物体
	mat = filament::Material::Builder()
		.package(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE)
		.build(*engine);

	triangle = new Triangle(engine, mat);
	scene->addEntity(triangle->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete camera;
	delete skybox;
	delete triangle;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	//auto& tcm = engine->getTransformManager();
	//tcm.setTransform(tcm.getInstance(cube), filament::math::mat4f::rotation(now, filament::math::float3{ 0, 0, 1 }));
}