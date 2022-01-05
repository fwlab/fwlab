#ifndef FLLAB_GL_OBJECT_MESH_H
#define FLLAB_GL_OBJECT_MESH_H
#include <utils/Entity.h>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "../core/Object3D.h"

namespace gl::object
{
	using gl::core::BufferGeometry;
	using gl::core::Object3D;
	using gl::material::Material;

	class Mesh : public Object3D
	{
	public:
		Mesh();
		virtual ~Mesh();
		void create(BufferGeometry* geometry, Material* material);
		bool culling = true;
		bool castShadows = false;
		bool receiveShadows = false;
		BufferGeometry* geometry = nullptr;
		Material* material = nullptr;
	};
}

#endif