#ifndef FWLAB_SCENE_SCENE_H
#define FWLAB_SCENE_SCENE_H
#include <gltfio/FilamentAsset.h>
#include <math/mat4.h>
#include "../light/AmbientLight.h"
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
		loader::TextureLoader* textureLoader = nullptr;
		object::Mesh* plane = nullptr;

		loader::GltfLoader* gltfLoader = nullptr;
		gltfio::FilamentAsset* asset = nullptr;
	};
}

#endif