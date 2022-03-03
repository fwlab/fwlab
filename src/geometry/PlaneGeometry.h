#ifndef FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#define FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#include <stdint.h>
#include <math/mat4.h>
#include <math/vec3.h>
#include "Geometry.h"

namespace fwlab::geometry
{
	class PlaneGeometry : public Geometry
	{
	public:
		class Builder
		{
		public:
			Builder* setWidth(float width);
			Builder* setHeight(float height);
			Builder* setWidthSegments(uint16_t widthSegments);
			Builder* setHeightSegments(uint16_t heightSegments);
			PlaneGeometry* build();

		private:
			float width = 1;
			float height = 1;
			uint16_t widthSegments = 1;
			uint16_t heightSegments = 1;
		};
	};
}

#endif