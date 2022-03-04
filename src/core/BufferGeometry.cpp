#include <float.h>
#include "../utils/Utils.h"
#include "BufferGeometry.h"
#include "../context/context.h"

namespace fwlab::core
{
	BufferGeometry::BufferGeometry()
	{
		this->groups = new std::vector<Group *>();
	}

	BufferGeometry::~BufferGeometry()
	{
		for (auto &pair : attributes)
		{
			delete pair.second;
			pair.second = nullptr;
		}
		attributes.clear();
		if (index)
		{
			delete index;
			index = nullptr;
		}
		if (boundingBox)
		{
			delete min;
			delete max;
			delete boundingBox;
			min = nullptr;
			max = nullptr;
			boundingBox = nullptr;
		}
		if (groups)
		{
			for (auto &group : *groups)
			{
				delete group;
				group = nullptr;
			}
			groups->clear();
			delete groups;
			groups = nullptr;
		}
		if (indices)
		{
			delete[] indices;
			indices = nullptr;
		}
	}

	void BufferGeometry::create()
	{
		createVertexBuffer();
		createIndexBuffer();
		computeBoundingBox();
	}

	Attributes BufferGeometry::getAttributes() const
	{
		return attributes;
	}

	bool BufferGeometry::hasAttribute(filament::VertexAttribute attrType) const
	{
		return attributes.count(attrType) > 0;
	}

	VertexBufferAttribute *BufferGeometry::getAttribute(filament::VertexAttribute attrType) const
	{
		if (!hasAttribute(attrType))
		{
			return nullptr;
		}
		return attributes.at(attrType);
	}

	void BufferGeometry::setAttribute(filament::VertexAttribute attrType, VertexBufferAttribute *attribute)
	{
		if (attributes.count(attrType) > 0)
		{
			auto &oldAttribute = attributes.at(attrType);
			delete oldAttribute;
			attributes.erase(attrType);
		}
		if (attribute)
		{
			attributes.insert({attrType, attribute});
		}
	}

	IndexBufferAttribute *BufferGeometry::getIndex() const
	{
		return index;
	}

	void BufferGeometry::setIndex(IndexBufferAttribute *index)
	{
		if (this->index)
		{
			delete this->index;
		}
		this->index = index;
	}

	filament::VertexBuffer *BufferGeometry::getVertexBuffer() const
	{
		return vertexBuffer;
	}

	void BufferGeometry::setVertexBuffer(filament::VertexBuffer *buffer)
	{
		auto engine = app->getEngine();

		if (vertexBuffer)
		{
			engine->destroy(vertexBuffer);
		}
		vertexBuffer = buffer;
	}

	filament::IndexBuffer *BufferGeometry::getIndexBuffer() const
	{
		return indexBuffer;
	}

	void BufferGeometry::setIndexBuffer(filament::IndexBuffer *buffer)
	{
		auto engine = app->getEngine();

		if (indexBuffer)
		{
			engine->destroy(indexBuffer);
		}
		indexBuffer = buffer;
	}

	filament::Box *BufferGeometry::getBoundingBox() const
	{
		return boundingBox;
	}

	void BufferGeometry::computeBoundingBox()
	{
		if (min)
		{
			delete min;
		}
		if (max)
		{
			delete max;
		}
		if (boundingBox)
		{
			delete boundingBox;
		}
		min = new filament::math::float3(FLT_MAX, FLT_MAX, FLT_MAX);
		max = new filament::math::float3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
		float *vertices = nullptr;
		uint32_t vertexCount = 0;

		auto attribute = attributes.at(filament::VertexAttribute::POSITION);
		if (attribute)
		{
			vertices = static_cast<float *>(attribute->getArray());
			vertexCount = attribute->getCount();
		}

		for (uint32_t i = 0, len = vertexCount; i < len; i++)
		{
			auto x = vertices[i * 3];
			auto y = vertices[i * 3 + 1];
			auto z = vertices[i * 3 + 2];
			if (x < min->x)
			{
				min->x = x;
			}
			if (y < min->y)
			{
				min->y = y;
			}
			if (z < min->z)
			{
				min->z = z;
			}
			if (x > max->x)
			{
				max->x = x;
			}
			if (y > max->y)
			{
				max->y = y;
			}
			if (z > max->z)
			{
				max->z = z;
			}
		}

		// no vertices
		if (min->x > max->x)
		{
			min->x = max->x = 0;
		}
		if (min->y > max->y)
		{
			min->y = max->y = 0;
		}
		if (min->z > max->z)
		{
			min->z = max->z = 0;
		}

		// only one vertex
		if (min->x == max->x)
		{
			min->x -= 1;
			max->x += 1;
		}
		if (min->y == max->y)
		{
			min->y -= 1;
			max->y += 1;
		}
		if (min->z == max->z)
		{
			min->z -= 1;
			max->z += 1;
		}

		boundingBox = new filament::Box();
		boundingBox->set(*min, *max);
	}

	void BufferGeometry::addGroup(int start, int count, int materialIndex)
	{
		Group *group = new Group{
			.start = start,
			.count = count,
			.materialIndex = materialIndex};

		groups->push_back(group);
	}

	void BufferGeometry::clearGroups()
	{
		for (auto &group : *groups)
		{
			delete group;
			group = nullptr;
		}
		groups->clear();
	}

	void BufferGeometry::createVertexBuffer()
	{
		auto engine = app->getEngine();

		assert(attributes.count(filament::VertexAttribute::POSITION) == 1);
		auto &vertices = attributes.at(filament::VertexAttribute::POSITION);

		auto builder = filament::VertexBuffer::Builder();
		builder.vertexCount(vertices->getCount());
		builder.bufferCount(attributes.size());

		uint16_t i = 0;
		for (auto pair : attributes)
		{
			builder.attribute(pair.first, i, pair.second->getAttributeType());
			if (pair.second->isNormalized())
			{
				builder.normalized(pair.first, true);
			}
			i++;
		}

		vertexBuffer = builder.build(*engine);

		i = 0;
		for (auto pair : attributes)
		{
			vertexBuffer->setBufferAt(
				*engine,
				i,
				filament::VertexBuffer::BufferDescriptor(
					pair.second->getArray(),
					pair.second->getCount() * utils::Utils::getSize(pair.second->getAttributeType())));
			i++;
		}
	}

	void BufferGeometry::createIndexBuffer()
	{
		auto engine = app->getEngine();

		if (index == nullptr)
		{
			return;
		}

		auto builder = filament::IndexBuffer::Builder();
		builder.indexCount(index->getCount());
		builder.bufferType(index->getIndexType());
		indexBuffer = builder.build(*engine);

		indexBuffer->setBuffer(
			*engine,
			filament::IndexBuffer::BufferDescriptor(
				index->getArray(),
				index->getCount() * utils::Utils::getSize(index->getIndexType())));
	}
}