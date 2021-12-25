#ifndef FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#define FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#include <stdint.h>
#include "../Context.h"
#include "../core/BufferGeometry.h"

/// <summary>
/// Æ½Ãæ
/// </summary>
class PlaneGeometry : public BufferGeometry {
public:
	PlaneGeometry(Context* context);
	void create(float width = 1, float height = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1);
};

#endif