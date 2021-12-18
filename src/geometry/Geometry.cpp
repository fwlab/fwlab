#include <climits>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include "Geometry.h"

using namespace filament;

Geometry::Geometry(Context* context)
{
	this->context = context;
}

Geometry::~Geometry()
{
	if (context && context->engine)
	{
		if (vertexBuffer)
		{
			context->engine->destroy(vertexBuffer);
		}
		if (indexBuffer)
		{
			context->engine->destroy(indexBuffer);
		}
	}
	if (boundingBox)
	{
		delete min;
		delete max;
		delete boundingBox;
	}
	if (indices)
	{
		delete[] indices;
	}
}

void Geometry::create()
{

}

void Geometry::create(float vertices[], uint32_t verticesSize)
{
	auto vertexCount = verticesSize / 3;
	indices = new uint16_t[vertexCount];

	for (uint32_t i = 0; i < vertexCount; i++)
	{
		indices[i] = i;
	}

	computeBoundingBox(vertices, verticesSize);

	vertexBuffer = VertexBuffer::Builder()
		.vertexCount(vertexCount)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT3)
		.build(*context->engine);
	vertexBuffer->setBufferAt(
		*context->engine, 0,
		VertexBuffer::BufferDescriptor(vertices, verticesSize * sizeof(float)));

	indexBuffer = IndexBuffer::Builder()
		.indexCount(vertexCount)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*context->engine);
	indexBuffer->setBuffer(
		*context->engine,
		IndexBuffer::BufferDescriptor(indices, vertexCount * sizeof(uint16_t))
	);
}

void Geometry::computeBoundingBox(float vertices[], uint32_t verticesSize)
{
	min = new filament::math::float3(FLT_MAX, FLT_MAX, FLT_MAX);
	max = new filament::math::float3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

	for (uint32_t i = 0, len = verticesSize / 3; i < len; i++)
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
		min->x -= 1;
		max->x += 1;
	}
	if (min->z == max->z)
	{
		min->x -= 1;
		max->x += 1;
	}

	boundingBox = new filament::Box();
	boundingBox->set(*min, *max);
}