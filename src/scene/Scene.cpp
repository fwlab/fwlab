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

		// light
		amlight = new light::AmbientLight("assets/ibl/lightroom_14b");
		scene->setSkybox(amlight->getSkybox());
		scene->setIndirectLight(amlight->getIndirectLight());

		// plane
		textureLoader = new loader::TextureLoader();
		auto texture = textureLoader->load("assets/images/girl.png", filament::Texture::Format::RGBA);

		auto geometry = new geometry::PlaneGeometry();
		geometry->create(10, 10);

		auto material = new material::UnlitMaterial();
		material->setMap(texture);

		plane = new object::Mesh(geometry, material);
		plane->setReceiveShadows(true);
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
		delete plane;
		delete textureLoader;
		delete amlight;

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
