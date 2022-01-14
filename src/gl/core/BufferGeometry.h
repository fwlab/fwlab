#ifndef GL_CORE_BUFFER_GEOMETRY_H
#define GL_CORE_BUFFER_GEOMETRY_H
#include <stdint.h>
#include <vector>
#include <filament/Box.h>
#include "BufferAttribute.h"

namespace gl::core
{
	using Attributes = std::unordered_map<filament::VertexAttribute, VertexBufferAttribute*>;

	struct Group
	{
		int start;
		int count;
		int materialIndex;
	};

	class BufferGeometry {
	public:
		BufferGeometry();
		virtual ~BufferGeometry();
		virtual void create() noexcept;

		Attributes getAttributes() const noexcept;
		bool hasAttribute(filament::VertexAttribute attrType) const noexcept;
		VertexBufferAttribute* getAttribute(filament::VertexAttribute attrType) const noexcept;
		void setAttribute(filament::VertexAttribute attrType, VertexBufferAttribute* attribute) noexcept;
		IndexBufferAttribute* getIndex() const noexcept;
		void setIndex(IndexBufferAttribute* index) noexcept;

		filament::VertexBuffer* getVertexBuffer() const noexcept;
		void setVertexBuffer(filament::VertexBuffer* buffer) noexcept;
		filament::IndexBuffer* getIndexBuffer() const noexcept;
		void setIndexBuffer(filament::IndexBuffer* buffer) noexcept;

		filament::Box* getBoundingBox() const noexcept;
		void computeBoundingBox() noexcept;

		void addGroup(int start, int count, int materialIndex = 0) noexcept;
		void clearGroups() noexcept;

	protected:
		virtual void createVertexBuffer() noexcept;
		virtual void createIndexBuffer() noexcept;
		Attributes attributes;
		IndexBufferAttribute* index = nullptr;
		filament::VertexBuffer* vertexBuffer = nullptr;
		filament::IndexBuffer* indexBuffer = nullptr;
		filament::Box* boundingBox = nullptr;
		std::vector<Group*>* groups = nullptr;

	private:
		uint16_t* indices = nullptr;
		filament::math::float3* min = nullptr;
		filament::math::float3* max = nullptr;
	};
}

#endif