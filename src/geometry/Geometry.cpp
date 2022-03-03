#include <float.h>
#include "Geometry.h"
#include "../context/context.h"

namespace fwlab::geometry
{
	Geometry::~Geometry()
	{
		delete boundingBox;
		delete vertices;
		delete normals;
		delete uvs;
		delete indices;
		delete tangents;
		delete min;
		delete max;
	}

	filament::VertexBuffer* Geometry::getVertexBuffer()
	{
		if (!vertexBuffer)
		{
			createVertexBuffer();
		}
		return vertexBuffer;
	}

	filament::IndexBuffer* Geometry::getIndexBuffer()
	{
		if (!indexBuffer)
		{
			createIndexBuffer();
		}
		return indexBuffer;
	}

	filament::Box* Geometry::getBoundingBox()
	{
		if (!boundingBox)
		{
			computeBoundingBox();
		}
		return boundingBox;
	}

	void Geometry::createVertexBuffer()
	{
		auto engine = app->getEngine();

		auto buffer = filament::VertexBuffer::Builder()
			.vertexCount(verticesSize / 3)
			.bufferCount(3)
			.attribute(filament::VertexAttribute::POSITION, 0, filament::VertexBuffer::AttributeType::FLOAT3)
			.attribute(filament::VertexAttribute::TANGENTS, 1, filament::VertexBuffer::AttributeType::SHORT4)
			.attribute(filament::VertexAttribute::UV0, 2, filament::VertexBuffer::AttributeType::FLOAT2)
			.normalized(filament::VertexAttribute::TANGENTS)
			.build(*engine);

		buffer->setBufferAt(*engine, 0, filament::VertexBuffer::BufferDescriptor(vertices, verticesSize * sizeof(float)));
		buffer->setBufferAt(*engine, 1, filament::VertexBuffer::BufferDescriptor(tangents, tangentsSize * sizeof(short) * 4));
		buffer->setBufferAt(*engine, 2, filament::VertexBuffer::BufferDescriptor(uvs, uvsSize * sizeof(float)));

		vertexBuffer = buffer;
	}

	void Geometry::createIndexBuffer()
	{
		auto engine = app->getEngine();

		auto buffer = filament::IndexBuffer::Builder()
			.indexCount(indicesSize)
			.bufferType(filament::IndexBuffer::IndexType::UINT)
			.build(*engine);

		buffer->setBuffer(*engine, filament::IndexBuffer::BufferDescriptor(indices, indicesSize * sizeof(uint32_t)));

		indexBuffer = buffer;
	}

	void Geometry::computeBoundingBox()
	{
		min = new filament::math::float3(FLT_MAX, FLT_MAX, FLT_MAX);
		max = new filament::math::float3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

		auto vertexCount = verticesSize / 3;

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
}