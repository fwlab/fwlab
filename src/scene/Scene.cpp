#include <filament/Camera.h>
#include <filament/Material.h>
#include <filament/Viewport.h>
#include <filament/TransformManager.h>

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
	view->setPostProcessingEnabled(false);

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
	constexpr float ZOOM = 1.5f;
	const uint32_t w = view->getViewport().width;
	const uint32_t h = view->getViewport().height;
	const float aspect = (float)w / h;
	camera->camera->setProjection(filament::Camera::Projection::ORTHO,
		-aspect * ZOOM, aspect * ZOOM,
		-ZOOM, ZOOM, 0, 1);
	filament::TransformManager& tcm = engine->getTransformManager();
	tcm.setTransform(tcm.getInstance(triangle->entity),
		filament::math::mat4f::rotation(now, filament::math::float3({ 0, 0, 1 })));
}