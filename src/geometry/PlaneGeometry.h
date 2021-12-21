#ifndef FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#define FWLAB_GEOMETRY_PLANE_GEOMETRY_H
#include <stdint.h>
#include "../Context.h"
#include "Geometry.h"

/// <summary>
/// Æ½Ãæ
/// </summary>
class PlaneGeometry : public Geometry {
public:
	PlaneGeometry(Context* context);
	virtual ~PlaneGeometry();
	PlaneGeometry* create(float width = 1, float height = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1);

private:
	float* vertices = nullptr;
	uint32_t verticesSize = 0;
	float* normals = nullptr;
	uint32_t normalsSize = 0;
	float* uvs = nullptr;
	uint32_t uvsSize = 0;
	uint16_t* indices = nullptr;
	uint32_t indicesSize = 0;
};

#endif