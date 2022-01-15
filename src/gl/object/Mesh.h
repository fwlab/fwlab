#ifndef FLLAB_GL_OBJECT_MESH_H
#define FLLAB_GL_OBJECT_MESH_H
#include <utils/Entity.h>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "../core/Object3D.h"

namespace gl::object
{
	class Mesh : public gl::core::Object3D
	{
	public:
		Mesh();
		Mesh(gl::core::BufferGeometry* geometry, gl::material::Material* material);
		virtual ~Mesh();
		bool getCulling() const noexcept;
		void setCulling(bool culling) noexcept;
		bool getCastShadows() const noexcept;
		void setCastShadows(bool castShadows) noexcept;
		bool getReceiveShadows() const noexcept;
		void setReceiveShadows(bool receiveShadows) noexcept;
		gl::core::BufferGeometry* getGeometry() const noexcept;
		void setGeometry(gl::core::BufferGeometry* geometry) noexcept;
		gl::material::Material* getMaterial() const noexcept;
		void setMaterial(gl::material::Material* material) noexcept;

	protected:
		bool culling = true;
		bool castShadows = false;
		bool receiveShadows = false;
		gl::core::BufferGeometry* geometry = nullptr;
		gl::material::Material* material = nullptr;
	};
}

#endif