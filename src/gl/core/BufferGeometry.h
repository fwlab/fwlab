#ifndef GL_CORE_BUFFER_GEOMETRY_H
#define GL_CORE_BUFFER_GEOMETRY_H
#include <stdint.h>
#include <filament/Box.h>
#include "../Context.h"
#include "BufferAttribute.h"

namespace gl::core
{
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
		uint16_t getSize(filament::VertexBuffer::AttributeType type);
		uint16_t getSize(filament::IndexBuffer::IndexType type);

	private:
		uint16_t* indices = nullptr;
		filament::math::float3* min = nullptr;
		filament::math::float3* max = nullptr;
	};
}

#endif