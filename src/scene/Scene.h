#ifndef FWLAB_SCENE_SCENE_H
#define FWLAB_SCENE_SCENE_H
#include <filament/Skybox.h>
#include <math/mat4.h>
#include <gltfio/AssetLoader.h>
#include <gltfio/FilamentAsset.h>
#include <gltfio/ResourceLoader.h>
#include <utils/NameComponentManager.h>
#include <utils/EntityManager.h>
#include "../object/Mesh.h"

namespace fwlab::scene
{
	class Scene {
	public:
		void create();
		void cleanup();
		void animate();

	private:
		filament::math::mat4f fitIntoUnitCube(const filament::Aabb& bounds, float zoffset);
		filament::Skybox* skybox;
		::utils::Entity lightEntity;
		object::Mesh* plane = nullptr;

		::utils::NameComponentManager* names;
		gltfio::AssetLoader* loader;
		gltfio::FilamentAsset* asset;
		gltfio::ResourceLoader* resourceLoader;
	};
}

#endif