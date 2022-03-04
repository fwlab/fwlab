#ifndef FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#define FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#include <stdint.h>
#include "../core/BufferGeometry.h"

namespace fwlab::geometry
{
	class PlaneGeometry : public core::BufferGeometry
	{
	public:
		PlaneGeometry();
		void create(float width = 1, float height = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1);
	};
}

#endif