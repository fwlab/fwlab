#ifndef FWLAB_GEOMETRY_GEOMETRY_H
#define FWLAB_GEOMETRY_GEOMETRY_H
#include <stdint.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Box.h>
#include "../Context.h"

/// <summary>
/// ¼¸ºÎÌå
/// </summary>
class Geometry {
public:
	Geometry(Context* context);
	virtual ~Geometry();
	Geometry* create();
	Geometry* create(float vertices[], uint32_t verticesSize);
	filament::VertexBuffer* vertexBuffer = nullptr;
	filament::IndexBuffer* indexBuffer = nullptr;
	filament::Box* boundingBox = nullptr;

protected:
	void computeBoundingBox(float vertices[], uint32_t verticesSize);
	Context* context = nullptr;

private:
	uint16_t* indices = nullptr;
	filament::math::float3* min = nullptr;
	filament::math::float3* max = nullptr;
};
#endif