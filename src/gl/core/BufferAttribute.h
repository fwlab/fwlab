#ifndef GL_CORE_BUFFER_ATTRIBUTE_H
#define GL_CORE_BUFFER_ATTRIBUTE_H
#include <stdint.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>

namespace gl::core
{
	template <typename T>
	class BufferAttribute {
	public:
		virtual ~BufferAttribute();
		T* array = nullptr;
		uint8_t itemSize = 0;
		uint32_t count = 0;
	};

	class VertexBufferAttribute : public BufferAttribute<float> {
	public:
		bool normalized = false;
		filament::VertexAttribute attribute = filament::VertexAttribute::POSITION;
		filament::VertexBuffer::AttributeType attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	};

	class IndexBufferAttribute : public BufferAttribute<uint32_t> {
	public:
		filament::IndexBuffer::IndexType indexType = filament::IndexBuffer::IndexType::UINT;
	};
}

#endif