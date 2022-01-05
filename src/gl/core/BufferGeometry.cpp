#include <climits>
#include "BufferGeometry.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;

BufferGeometry::BufferGeometry()
{
	this->groups = new std::vector<Group*>();
}

BufferGeometry::~BufferGeometry()
{
	for (auto& pair : attributes)
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
		for (auto& group : *groups)
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

void BufferGeometry::createVertexBuffer()
{
	assert(attributes.count(filament::VertexAttribute::POSITION) == 1);
	auto vertices = attributes.at(filament::VertexAttribute::POSITION);

	auto builder = filament::VertexBuffer::Builder();
	builder.vertexCount(vertices->count);
	builder.bufferCount(attributes.size());

	uint16_t i = 0;
	for (auto pair : attributes)
	{
		builder.attribute(pair.second->attribute, i, pair.second->attributeType);
		if (pair.second->normalized)
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
			filament::VertexBuffer::BufferDescriptor(pair.second->array, pair.second->count * getSize(pair.second->attributeType))
		);
		i++;
	}
}

void BufferGeometry::createIndexBuffer()
{
	if (index == nullptr)
	{
		return;
	}
	auto builder = filament::IndexBuffer::Builder();
	builder.indexCount(index->count);
	builder.bufferType(index->indexType);
	indexBuffer = builder.build(*engine);

	indexBuffer->setBuffer(
		*engine,
		filament::IndexBuffer::BufferDescriptor(index->array, index->count * getSize(index->indexType))
	);
}

void BufferGeometry::computeBoundingBox()
{
	min = new filament::math::float3(FLT_MAX, FLT_MAX, FLT_MAX);
	max = new filament::math::float3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
	float* vertices = nullptr;
	uint32_t vertexCount = 0;

	auto attribute = attributes.at(filament::VertexAttribute::POSITION);
	if (attribute)
	{
		vertices = static_cast<float*>(attribute->array);
		vertexCount = attribute->count;
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
	Group* group = new Group{
		.start = start,
		.count = count,
		.materialIndex = materialIndex };

	groups->push_back(group);
}

void BufferGeometry::clearGroups()
{
	for (auto& group : *groups)
	{
		delete group;
		group = nullptr;
	}
	groups->clear();
}

uint16_t BufferGeometry::getSize(filament::VertexBuffer::AttributeType type)
{
	switch (type)
	{
	case filament::VertexBuffer::AttributeType::BYTE:
		return 1;
	case filament::VertexBuffer::AttributeType::BYTE2:
		return 2;
	case filament::VertexBuffer::AttributeType::BYTE3:
		return 3;
	case filament::VertexBuffer::AttributeType::BYTE4:
		return 4;
	case filament::VertexBuffer::AttributeType::FLOAT:
		return 4;
	case filament::VertexBuffer::AttributeType::FLOAT2:
		return 8;
	case filament::VertexBuffer::AttributeType::FLOAT3:
		return 12;
	case filament::VertexBuffer::AttributeType::FLOAT4:
		return 16;
	case filament::VertexBuffer::AttributeType::HALF:
		return 2;
	case filament::VertexBuffer::AttributeType::HALF2:
		return 4;
	case filament::VertexBuffer::AttributeType::HALF3:
		return 6;
	case filament::VertexBuffer::AttributeType::HALF4:
		return 8;
	case filament::VertexBuffer::AttributeType::INT:
		return 4;
	case filament::VertexBuffer::AttributeType::SHORT:
		return 2;
	case filament::VertexBuffer::AttributeType::SHORT2:
		return 4;
	case filament::VertexBuffer::AttributeType::SHORT3:
		return 6;
	case filament::VertexBuffer::AttributeType::SHORT4:
		return 8;
	case filament::VertexBuffer::AttributeType::UBYTE:
		return 1;
	case filament::VertexBuffer::AttributeType::UBYTE2:
		return 2;
	case filament::VertexBuffer::AttributeType::UBYTE3:
		return 3;
	case filament::VertexBuffer::AttributeType::UBYTE4:
		return 4;
	case filament::VertexBuffer::AttributeType::UINT:
		return 4;
	case filament::VertexBuffer::AttributeType::USHORT:
		return 2;
	case filament::VertexBuffer::AttributeType::USHORT2:
		return 4;
	case filament::VertexBuffer::AttributeType::USHORT3:
		return 6;
	case filament::VertexBuffer::AttributeType::USHORT4:
		return 8;
	default:
		throw "unknown vertex attribute type";
	}
}

uint16_t BufferGeometry::getSize(filament::IndexBuffer::IndexType type)
{
	switch (type)
	{
	case filament::IndexBuffer::IndexType::USHORT:
		return 2;
	case filament::IndexBuffer::IndexType::UINT:
		return 4;
	default:
		throw "unknown index buffer type";
	}
}