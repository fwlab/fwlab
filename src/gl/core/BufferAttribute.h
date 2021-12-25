#ifndef FWLAB_BUFFER_ATTRIBUTE_H
#define FWLAB_BUFFER_ATTRIBUTE_H
#include <stdint.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include "../Context.h"

template <typename T>
class BufferAttribute {
public:
	BufferAttribute(Context* context);
	virtual ~BufferAttribute();
	T* array = nullptr;
	uint8_t itemSize = 0;
	uint32_t count = 0;

protected:
	Context* context = nullptr;
};

class VertexBufferAttribute : public BufferAttribute<float> {
public:
	VertexBufferAttribute(Context* context);
	bool normalized = false;
	filament::VertexAttribute attribute = filament::VertexAttribute::POSITION;
	filament::VertexBuffer::AttributeType attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
};

class IndexBufferAttribute : public BufferAttribute<uint32_t> {
public:
	IndexBufferAttribute(Context* context);
	filament::IndexBuffer::IndexType indexType = filament::IndexBuffer::IndexType::UINT;
};

#endif