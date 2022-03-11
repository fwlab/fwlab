#include <fstream>
#include <filament/LightManager.h>
#include <filament/TransformManager.h>
#include <utils/Path.h>
#include "SceneGraph.h"
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
		auto amlight = new light::AmbientLight("assets/ibl/lightroom_14b");
		scene->addAmbientLight(amlight);

		// plane
		textureLoader = new loader::TextureLoader();
		auto texture = textureLoader->load("assets/images/girl.png", filament::Texture::Format::RGBA);

		auto geometry = new geometry::PlaneGeometry();
		geometry->create(10, 10);

		auto material = new material::UnlitMaterial();
		material->setMap(texture);

		plane = new object::Mesh(geometry, material);
		plane->setName("正方体");
		plane->setReceiveShadows(true);
		plane->setRotation({ 1, 0, 0 }, -M_PI / 2);

		scene->add(plane);

		// gltf
		gltfLoader = new loader::GltfLoader();
		gltfLoader->load("assets/models/RobotDog/scene.gltf", [&](core::Object3D* obj) {
			dog = obj;
			dog->setName("机器狗");
			app->getScene()->add(dog);
			});
	}

	void Scene::cleanup()
	{
		delete plane;
		delete dog;
		delete textureLoader;
		delete gltfLoader;
	}

	void Scene::animate()
	{
		if (dog)
		{
			dog->setRotation({ 1, 0, 0 }, M_PI / 2);
			dog->setScale({ 0.0002, 0.0002, 0.0002 });
		}
	}
}
