#include <cmath>
#include "../core/BufferAttribute.h"
#include "PlaneGeometry.h"

using namespace gl::core;
using namespace gl::geometry;

PlaneGeometry::PlaneGeometry(Context* context) : BufferGeometry(context)
{

}

void PlaneGeometry::create(float width, float height, uint16_t widthSegments, uint16_t heightSegments)
{
	float width_half = width / 2;
	float height_half = height / 2;

	uint16_t gridX = widthSegments;
	uint16_t gridY = heightSegments;

	uint16_t gridX1 = gridX + 1;
	uint16_t gridY1 = gridY + 1;

	float segment_width = width / gridX;
	float segment_height = height / gridY;

	//
	uint32_t verticesSize = gridY1 * gridX1 * 3;
	uint32_t normalsSize = gridY1 * gridX1 * 3;
	uint32_t uvsSize = gridY1 * gridX1 * 2;
	uint32_t indicesSize = gridY * gridX * 6;

	float* vertices = new float[verticesSize];
	float* normals = new float[normalsSize];
	float* uvs = new float[uvsSize];
	uint32_t* triangles = new uint32_t[indicesSize];

	for (uint16_t iy = 0; iy < gridY1; iy++) {
		double y = iy * segment_height - height_half;

		for (uint16_t ix = 0; ix < gridX1; ix++) {
			uint32_t index = gridX1 * iy + ix;
			float x = ix * segment_width - width_half;

			vertices[index * 3] = float(x);
			vertices[index * 3 + 1] = float(-y);
			vertices[index * 3 + 2] = 0;

			normals[index * 3] = 0;
			normals[index * 3 + 1] = 0;
			normals[index * 3 + 2] = 1;

			uvs[index * 2] = ix / gridX;
			uvs[index * 2 + 1] = 1 - (iy / gridY);
		}
	}

	for (uint16_t iy = 0; iy < gridY; iy++) {
		for (uint16_t ix = 0; ix < gridX; ix++) {
			uint32_t index = gridX * iy + ix;

			float a = ix + gridX1 * iy;
			float b = ix + gridX1 * (iy + 1);
			float c = (ix + 1) + gridX1 * (iy + 1);
			float d = (ix + 1) + gridX1 * iy;

			triangles[index * 6] = a;
			triangles[index * 6 + 1] = b;
			triangles[index * 6 + 2] = d;
			triangles[index * 6 + 3] = b;
			triangles[index * 6 + 4] = c;
			triangles[index * 6 + 5] = d;
		}
	}

	// position
	auto position = new VertexBufferAttribute(context);
	position->array = vertices;
	position->attribute = filament::VertexAttribute::POSITION;
	position->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	position->itemSize = 3;
	position->count = verticesSize / position->itemSize;
	attributes.insert({ filament::VertexAttribute::POSITION, position });

	// normal
	auto normal = new VertexBufferAttribute(context);
	normal->array = normals;
	normal->attribute = filament::VertexAttribute::TANGENTS;
	normal->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	normal->itemSize = 3;
	normal->count = normalsSize / normal->itemSize;
	attributes.insert({ filament::VertexAttribute::TANGENTS, normal });

	// uv
	auto uv = new VertexBufferAttribute(context);
	uv->array = uvs;
	uv->attribute = filament::VertexAttribute::UV0;
	uv->attributeType = filament::VertexBuffer::AttributeType::FLOAT2;
	uv->itemSize = 2;
	uv->count = uvsSize / uv->itemSize;
	attributes.insert({ filament::VertexAttribute::UV0, uv });

	// index
	index = new IndexBufferAttribute(context);
	index->array = triangles;
	index->indexType = filament::IndexBuffer::IndexType::UINT;
	index->itemSize = 1;
	index->count = indicesSize / index->itemSize;

	BufferGeometry::create();
}