#include <filament/Camera.h>
#include <filament/Texture.h>
#include <filament/Material.h>
#include <filament/Viewport.h>
#include <filament/TransformManager.h>
#include <filameshio/MeshReader.h>
#include <utils/EntityManager.h>
#include <filament/LightManager.h>

#include "../Context.h"
#include "../loader/FilameshLoader.h"
#include "resources/resources.h"
#include "Scene.h"

Context context;

FilameshLoader* loader;
Material* material;
Mesh* mesh;
utils::Entity light;
filament::MaterialInstance* mi;
filament::math::mat4f transform;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	context = { engine, view, scene };

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
	transform = filament::math::mat4f{
		filament::math::mat3f(1),
		filament::math::float3(0, 0, -4) } *tcm.getWorldTransform(ti);
	//rcm.setCastShadows(rcm.getInstance(app.mesh.renderable), false);
	scene->addEntity(mesh->entity);

	// Add light sources into the scene.
	light = em.create();
	filament::LightManager::Builder(filament::LightManager::Type::SUN)
		.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(filament::sRGBColor(0.98f, 0.92f, 0.89f)))
		.intensity(110000)
		.direction({ 0.7, -1, -0.8 })
		.sunAngularRadius(1.9f)
		.castShadows(false)
		.build(*engine, light);
	scene->addEntity(light);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	engine->destroy(mi);
	delete material;
	engine->destroy(light);
	delete mesh;
	delete loader;
}

void Scene::animate(filament::Engine* engine, filament::View* view, double now)
{
	auto& tcm = engine->getTransformManager();
	auto ti = tcm.getInstance(mesh->entity);
	tcm.setTransform(ti, transform * filament::math::mat4f::rotation(now, filament::math::float3{ 0, 1, 0 }));
}