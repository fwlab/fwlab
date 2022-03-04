#ifndef FWLAB_CORE_BUFFER_GEOMETRY_H
#define FWLAB_CORE_BUFFER_GEOMETRY_H
#include <stdint.h>
#include <vector>
#include <unordered_map>
#include <filament/Box.h>
#include "BufferAttribute.h"

namespace fwlab::core
{
	using Attributes = std::unordered_map<filament::VertexAttribute, VertexBufferAttribute *>;

	struct Group
	{
		int start;
		int count;
		int materialIndex;
	};

	class BufferGeometry
	{
	public:
		BufferGeometry();
		virtual ~BufferGeometry();
		virtual void create();

		Attributes getAttributes() const;
		bool hasAttribute(filament::VertexAttribute attrType) const;
		VertexBufferAttribute *getAttribute(filament::VertexAttribute attrType) const;
		void setAttribute(filament::VertexAttribute attrType, VertexBufferAttribute *attribute);
		IndexBufferAttribute *getIndex() const;
		void setIndex(IndexBufferAttribute *index);

		filament::VertexBuffer *getVertexBuffer() const;
		void setVertexBuffer(filament::VertexBuffer *buffer);
		filament::IndexBuffer *getIndexBuffer() const;
		void setIndexBuffer(filament::IndexBuffer *buffer);

		filament::Box *getBoundingBox() const;
		void computeBoundingBox();

		void addGroup(int start, int count, int materialIndex = 0);
		void clearGroups();

	protected:
		virtual void createVertexBuffer();
		virtual void createIndexBuffer();
		Attributes attributes;
		IndexBufferAttribute *index = nullptr;
		filament::VertexBuffer *vertexBuffer = nullptr;
		filament::IndexBuffer *indexBuffer = nullptr;
		filament::Box *boundingBox = nullptr;
		std::vector<Group *> *groups = nullptr;

	private:
		uint16_t *indices = nullptr;
		filament::math::float3 *min = nullptr;
		filament::math::float3 *max = nullptr;
	};
}

#endif