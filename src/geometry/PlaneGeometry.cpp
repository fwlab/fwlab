#include <cmath>
#include "../core/BufferAttribute.h"
#include "PlaneGeometry.h"

namespace fwlab::geometry
{
	PlaneGeometry::PlaneGeometry()
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

		for (uint16_t iy = 0; iy < gridY1; iy++)
		{
			double y = iy * segment_height - height_half;

			for (uint16_t ix = 0; ix < gridX1; ix++)
			{
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

		for (uint16_t iy = 0; iy < gridY; iy++)
		{
			for (uint16_t ix = 0; ix < gridX; ix++)
			{
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
		auto position = new core::VertexBufferAttribute(vertices, 3, verticesSize / 3);
		attributes.insert({ filament::VertexAttribute::POSITION, position });

		// normal
		auto normal = new core::VertexBufferAttribute(normals, 3, normalsSize / 3);
		attributes.insert({ filament::VertexAttribute::TANGENTS, normal });

		// uv
		auto uv = new core::VertexBufferAttribute(uvs, 2, uvsSize / 2, filament::VertexBuffer::AttributeType::FLOAT2);
		attributes.insert({ filament::VertexAttribute::UV0, uv });

		// index
		index = new core::IndexBufferAttribute(triangles, indicesSize);

		BufferGeometry::create();
	}
}