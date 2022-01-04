#ifndef GL_CORE_BUFFER_ATTRIBUTE_H
#define GL_CORE_BUFFER_ATTRIBUTE_H
#include <stdint.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>

namespace gl::core
{
	class BufferAttribute {
	public:
		BufferAttribute(void* array = nullptr, uint8_t itemSize = 0);
		virtual ~BufferAttribute();
		void* array = nullptr;
		uint8_t itemSize = 0;
		uint32_t count = 0;
	};

	class VertexBufferAttribute : public BufferAttribute {
	public:
		VertexBufferAttribute(void* array = nullptr, uint8_t itemSize = 0, bool normalized = false);
		bool normalized = false;
		filament::VertexAttribute attribute = filament::VertexAttribute::POSITION;
		filament::VertexBuffer::AttributeType attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	};

	class IndexBufferAttribute : public BufferAttribute {
	public:
		IndexBufferAttribute(void* array = nullptr, uint8_t itemSize = 0);
		filament::IndexBuffer::IndexType indexType = filament::IndexBuffer::IndexType::UINT;
	};
}

#endif