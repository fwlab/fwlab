#ifndef GL_GEOMETRY_PLANE_GEOMETRY_H
#define GL_GEOMETRY_PLANE_GEOMETRY_H
#include <stdint.h>
#include "../Context.h"
#include "../core/BufferGeometry.h"

namespace gl::geometry
{
	class PlaneGeometry : public gl::core::BufferGeometry {
	public:
		PlaneGeometry(Context* context);
		void create(float width = 1, float height = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1);
	};
}

#endif