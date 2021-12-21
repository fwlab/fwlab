#include <cmath>
#include "PlaneGeometry.h"

PlaneGeometry::PlaneGeometry(Context* context) : Geometry(context)
{
}

PlaneGeometry::~PlaneGeometry()
{
	if (vertices)
	{
		delete[] vertices;
	}
	if (normals)
	{
		delete[] normals;
	}
	if (uvs)
	{
		delete[] uvs;
	}
	if (indices)
	{
		delete[] indices;
	}
}

PlaneGeometry* PlaneGeometry::create(float width, float height, uint16_t widthSegments, uint16_t heightSegments)
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
	verticesSize = gridY1 * gridX1 * 3;
	normalsSize = gridY1 * gridX1 * 3;
	uvsSize = gridY1 * gridX1 * 2;
	indicesSize = gridY * gridX * 6;

	vertices = new float[verticesSize];
	normals = new float[normalsSize];
	uvs = new float[uvsSize];
	indices = new uint16_t[indicesSize];

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

			indices[index * 6] = a;
			indices[index * 6 + 1] = b;
			indices[index * 6 + 2] = d;
			indices[index * 6 + 3] = b;
			indices[index * 6 + 4] = c;
			indices[index * 6 + 5] = d;
		}
	}

	//this.setIndex(indices);
	//this.setAttribute('position', new Float32BufferAttribute(vertices, 3));
	//this.setAttribute('normal', new Float32BufferAttribute(normals, 3));
	//this.setAttribute('uv', new Float32BufferAttribute(uvs, 2));
	Geometry::create(vertices, verticesSize, indices, indicesSize);

	return this;
}