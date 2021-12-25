#ifndef FWLAB_BUFFER_GEOMETRY_GEOMETRY_H
#define FWLAB_BUFFER_GEOMETRY_GEOMETRY_H
#include <stdint.h>
#include <filament/Box.h>
#include "../Context.h"
#include "BufferAttribute.h"

class BufferGeometry {
public:
	BufferGeometry(Context* context);
	virtual ~BufferGeometry();
	virtual void create();
	void computeBoundingBox();
	std::unordered_map<filament::VertexAttribute, VertexBufferAttribute*> attributes;
	IndexBufferAttribute* index = nullptr;
	filament::VertexBuffer* vertexBuffer = nullptr;
	filament::IndexBuffer* indexBuffer = nullptr;
	filament::Box* boundingBox = nullptr;

protected:
	Context* context = nullptr;
	virtual void createVertexBuffer();
	virtual void createIndexBuffer();

private:
	uint16_t* indices = nullptr;
	filament::math::float3* min = nullptr;
	filament::math::float3* max = nullptr;
};
#endif