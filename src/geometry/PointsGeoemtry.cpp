#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include "PointsGeometry.h"

using namespace filament;

PointsGeoemtry::PointsGeoemtry(Context* context) : Geometry(context)
{

}

PointsGeoemtry::~PointsGeoemtry()
{
	if (indices)
	{
		delete[] indices;
	}
}

void PointsGeoemtry::create(float vertices[], uint32_t verticesSize)
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
		.indexCount(1)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*context->engine);
	indexBuffer->setBuffer(
		*context->engine,
		IndexBuffer::BufferDescriptor(indices, vertexCount * sizeof(uint16_t))
	);
}