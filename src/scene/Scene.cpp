#include <filament/Camera.h>
#include <filament/Texture.h>
#include <filament/Material.h>
#include <filament/Viewport.h>
#include <filament/TransformManager.h>
#include <filameshio/MeshReader.h>
#include <utils/EntityManager.h>
#include <filament/LightManager.h>

#include "../Context.h"
#include "../light/Light.h"
#include "../loader/FilameshLoader.h"
#include "resources/resources.h"
#include "Scene.h"

Context context;

FilameshLoader* loader;
Material* material;
Mesh* mesh;
Light* light;
filament::MaterialInstance* mi;
filament::math::mat4f transform;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	context = { engine, view, scene };

	light = new Light(&context);
	light->create();
	scene->addEntity(light->entity);

	auto& tcm = engine->getTransformManager();
	auto& rcm = engine->getRenderableManager();
	auto& em = utils::EntityManager::get();

	material = new Material(&context);
	material->create(RESOURCES_AIDEFAULTMAT_DATA, RESOURCES_AIDEFAULTMAT_SIZE);
	mi = material->createInstance();
	mi->setParameter("baseColor", filament::RgbType::LINEAR, filament::math::float3{ 0.8 });
	mi->setParameter("metallic", 1.0f);
	mi->setParameter("roughness", 0.4f);
	mi->setParameter("reflectance", 0.5f);

	loader = new FilameshLoader(&context);
	mesh = loader->load(RESOURCES_MONKEY_DATA, mi);

	auto ti = tcm.getInstance(mesh->entity);
	filament::math::mat4f mat4 = filament::math::mat4f{
		filament::math::mat3f(1),
		filament::math::float3(0, 0, -4) };
	transform = mat4 * tcm.getWorldTransform(ti);
	//rcm.setCastShadows(rcm.getInstance(app.mesh.renderable), false);
	scene->addEntity(mesh->entity);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	engine->destroy(mi);
	delete material;
	delete mesh;
	delete loader;
	delete light;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	//if (!mesh)
	//{
	//	return;
	//}
	//mesh->setRotation(now, filament::math::double3{ 0, 1, 0 });

	auto& tcm = engine->getTransformManager();
	auto ti = tcm.getInstance(mesh->entity);
	tcm.setTransform(ti, transform * filament::math::mat4f::rotation(now, filament::math::float3{ 0, 1, 0 }));
}