#include <filament/Camera.h>
#include <filament/Texture.h>
#include <filament/Material.h>
#include <filament/Viewport.h>
#include <filament/TransformManager.h>
#include "../Context.h"
#include "../camera/OrthographicCamera.h"
#include "../object/Skybox.h"
#include "../geometry/Geometry.h"
#include "../material/MeshBasicMaterial.h"
#include "../material/PointsMaterial.h"
#include "../material/LineBasicMaterial.h"
#include "../object/Mesh.h"
#include "Scene.h"

Context context;
OrthographicCamera* camera;
Skybox* skybox;

Geometry* geometry;
Material* material;
Mesh* object;

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
	static float vertices[] = { -0.5, 0, 0, 0.5, 0, 0, 0, 0.5, 0 };

	geometry = new Geometry(&context);
	geometry->create(vertices, sizeof(vertices) / sizeof(float));

	material = new MeshBasicMaterial(&context);
	material->create();

	object = new Mesh(&context);
	object->create(geometry, material);
	scene->addEntity(object->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete camera;
	delete skybox;
	delete object;
	delete material;
	delete geometry;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	//filament::TransformManager& tcm = engine->getTransformManager();
	//tcm.setTransform(tcm.getInstance(triangle->entity),
	//	filament::math::mat4f::rotation(now, filament::math::float3({ 0, 0, 1 })));
}