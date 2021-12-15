#include <filament/Camera.h>
#include <filament/Texture.h>
#include <filament/Material.h>
#include <filament/Viewport.h>
#include <filament/TransformManager.h>

#include "../Context.h"
#include "../camera/OrthographicCamera.h"
#include "../object/Skybox.h"
#include "../object/Triangle.h"

#include "resources/resources.h"
#include "scene.h"

Context context;
OrthographicCamera* camera;
Skybox* skybox;
filament::Material* mat;
Triangle* triangle;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	context = { engine, view, scene };
	view->setPostProcessingEnabled(false);

	// 相机
	camera = new OrthographicCamera(&context);

	// 天空盒
	skybox = new Skybox(&context);
	scene->setSkybox(skybox->skybox);

	// 物体
	mat = filament::Material::Builder()
		.package(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE)
		.build(*engine);

	triangle = new Triangle(&context, mat);
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
	filament::TransformManager& tcm = engine->getTransformManager();
	tcm.setTransform(tcm.getInstance(triangle->entity),
		filament::math::mat4f::rotation(now, filament::math::float3({ 0, 0, 1 })));
}