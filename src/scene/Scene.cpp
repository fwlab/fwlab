#include "../Context.h"
#include "../light/Light.h"
#include "../loader/FilameshLoader.h"
#include "resources/resources.h"
#include "Scene.h"

Context context;
Light* light;
Material* material;
filament::MaterialInstance* materialIndex;
FilameshLoader* loader;
Mesh* mesh;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	context = { engine, view, scene };

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
	mesh->setTranslation({ 0, 0, -4 });

	scene->addEntity(mesh->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	engine->destroy(materialIndex);
	delete material;
	delete light;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	mesh->setRotation(now, filament::math::double3{ 0, 1, 0 });
}