#ifndef FWLAB_SCENE_SCENE_H
#define FWLAB_SCENE_SCENE_H
#include <filament/Skybox.h>
#include <gltfio/FilamentAsset.h>
#include <math/mat4.h>
#include <utils/Entity.h>
#include "../object/Mesh.h"
#include "../loader/TextureLoader.h"
#include "../loader/GltfLoader.h"

namespace fwlab::scene
{
	class Scene {
	public:
		void create();
		void cleanup();
		void animate();

	private:
		filament::Skybox* skybox = nullptr;

		::utils::Entity lightEntity;

		loader::TextureLoader* textureLoader = nullptr;
		object::Mesh* plane = nullptr;

		loader::GltfLoader* gltfLoader = nullptr;
		gltfio::FilamentAsset* asset = nullptr;
	};
}

#endif