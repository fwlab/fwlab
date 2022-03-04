#include <iostream>
#include <fstream>
#include <filament/LightManager.h>
#include <filament/TransformManager.h>
#include <utils/Path.h>
#include "Scene.h"
#include "../context/context.h"
#include "../geometry/PlaneGeometry.h"
#include "../material/UnlitMaterial.h"
#include "../math/mat4.h"

namespace fwlab::scene
{
	void Scene::create()
	{
		auto engine = app->getEngine();
		auto scene = app->getScene();
		auto& entityManager = ::utils::EntityManager::get();

		// skybox
		skybox = filament::Skybox::Builder()
			.color({ 0.1, 0.125, 0.25, 1.0 })
			.showSun(true)
			.build(*engine);
		scene->setSkybox(skybox);

		// light
		lightEntity = entityManager.create();
		filament::LightManager::Builder(filament::LightManager::Type::SUN)
			.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(filament::sRGBColor(0.98f, 0.92f, 0.89f)))
			.intensity(110000)
			.sunAngularRadius(1.9f)
			.castShadows(true)
			.build(*engine, lightEntity);
		scene->addEntity(lightEntity);

		// plane
		textureLoader = new loader::TextureLoader();
		auto texture = textureLoader->load("assets/images/girl.png", filament::Texture::Format::RGBA);

		auto geometry = new geometry::PlaneGeometry();
		geometry->create(10, 10);

		auto material = new material::UnlitMaterial();
		material->setMap(texture);

		plane = new object::Mesh(geometry, material);
		plane->setRotation({ 1, 0, 0 }, -M_PI / 2);

		scene->addEntity(plane->getEntity());

		// gltf
		gltfLoader = new loader::GltfLoader();
		asset = gltfLoader->load("assets/models/RobotDog/scene.gltf");
		if (asset)
		{
			scene->addEntities(asset->getEntities(), asset->getEntityCount());
		}
	}

	void Scene::cleanup()
	{
		auto engine = app->getEngine();
		engine->destroy(skybox);
		engine->destroy(lightEntity);
		delete plane;
		delete textureLoader;

		gltfLoader->destroyAsset(asset);
		gltfLoader->destroy();
		delete gltfLoader;
	}

	void Scene::animate()
	{
		auto engine = app->getEngine();

		if (gltfLoader)
		{
			gltfLoader->update();
		}

		if (asset)
		{
			auto& manager = engine->getTransformManager();
			auto root = manager.getInstance(asset->getRoot());

			filament::math::double3 position = { 0, 0, 0 };

			filament::math::double3 axis = { 1, 0, 0 };
			double angle = M_PI / 2;
			filament::math::quat rotation = filament::math::quat::fromAxisAngle(axis, angle);

			filament::math::float3 scale = { 0.0002, 0.0002, 0.0002 };

			auto transform = math::compose(position, rotation, scale);
			manager.setTransform(root, transform);
		}
	}
}
