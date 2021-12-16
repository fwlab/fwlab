#ifndef FWLAB_GEOMETRY_GEOMETRY_H
#define FWLAB_GEOMETRY_GEOMETRY_H
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Box.h>
#include "../Context.h"

/// <summary>
/// 几何体基类
/// </summary>
class Geometry {
public:
	Geometry(Context* context);
	virtual ~Geometry();
	void create();
	filament::VertexBuffer* vertexBuffer = nullptr;
	filament::IndexBuffer* indexBuffer = nullptr;
	filament::Box* boundingBox = nullptr;

protected:
	void computeBoundingBox(float vertices[], uint32_t verticesSize);
	Context* context = nullptr;
};
#endif