#include <cmath>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <geometry/SurfaceOrientation.h>
#include "../utils/Logger.h"
#include "BoxGeometry.h"

using namespace gl::core;
using namespace gl::geometry;
using namespace gl::utils;

BoxGeometry::BoxGeometry()
{
}

BoxGeometry::~BoxGeometry()
{
	//if (tangents)
	//{
	//	delete tangents;
	//}
}

void BoxGeometry::create(float width, float height, float depth, uint16_t widthSegments, uint16_t heightSegments, uint16_t depthSegments)
{
	// helper variables
	numberOfVertices = 0;
	groupStart = 0;

	// build each side of the box geometry
	buildPlane("z", "y", "x", -1, -1, depth, height, width, depthSegments, heightSegments, 0);  // px
	buildPlane("z", "y", "x", 1, -1, depth, height, -width, depthSegments, heightSegments, 1);  // nx
	buildPlane("x", "z", "y", 1, 1, width, depth, height, widthSegments, depthSegments, 2);     // py
	buildPlane("x", "z", "y", 1, -1, width, depth, -height, widthSegments, depthSegments, 3);   // ny
	buildPlane("x", "y", "z", 1, -1, width, height, depth, widthSegments, heightSegments, 4);   // pz
	buildPlane("x", "y", "z", -1, -1, width, height, -depth, widthSegments, heightSegments, 5); // nz

	// position
	uint32_t vertexCount = vertices.size();
	float* _vertices = new float[vertexCount * 3];
	for (uint32_t i = 0; i < vertexCount; i++)
	{
		auto vertex = vertices[i];
		_vertices[i * 3] = vertex.x;
		_vertices[i * 3 + 1] = vertex.y;
		_vertices[i * 3 + 2] = vertex.z;
	}

	auto position = new VertexBufferAttribute();
	position->array = _vertices;
	position->attribute = filament::VertexAttribute::POSITION;
	position->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	position->itemSize = 3;
	position->count = vertexCount;
	attributes.insert({ filament::VertexAttribute::POSITION, position });

	// uv
	uint32_t uvCount = uvs.size();
	float* _uvs = new float[uvCount * 2];
	for (uint32_t i = 0; i < uvCount; i++)
	{
		auto uv = uvs[i];
		_uvs[i * 2] = uv.x;
		_uvs[i * 2 + 1] = uv.y;
	}

	auto uv = new VertexBufferAttribute();
	uv->array = _uvs;
	uv->attribute = filament::VertexAttribute::UV0;
	uv->attributeType = filament::VertexBuffer::AttributeType::FLOAT2;
	uv->itemSize = 2;
	uv->count = uvCount;
	attributes.insert({ filament::VertexAttribute::UV0, uv });

	// index
	uint32_t triangleCount = triangles.size();
	uint32_t* _indices = new uint32_t[triangleCount * 3];
	for (uint32_t i = 0; i < triangleCount; i++)
	{
		auto index = triangles[i];
		_indices[i * 3] = index.x;
		_indices[i * 3 + 1] = index.y;
		_indices[i * 3 + 2] = index.z;
	}

	index = new IndexBufferAttribute();
	index->array = _indices;
	index->indexType = filament::IndexBuffer::IndexType::UINT;
	index->itemSize = 1;
	index->count = triangleCount * 3;

	// normal
	uint32_t normalCount = normals.size();
	float* _normals = new float[normalCount * 3];
	for (uint32_t i = 0; i < normalCount; i++)
	{
		auto normal = normals[i];
		_normals[i * 3] = normal.x;
		_normals[i * 3 + 1] = normal.y;
		_normals[i * 3 + 2] = normal.z;
	}

	auto* quats = filament::geometry::SurfaceOrientation::Builder()
		.vertexCount(vertexCount)
		.positions(vertices.data())
		.normals(normals.data())
		.uvs(uvs.data())
		.triangleCount(triangleCount)
		.triangles(triangles.data())
		.build();
	tangents = new filament::math::short4[vertexCount];
	quats->getQuats(tangents, vertexCount, sizeof(filament::math::short4));
	delete quats;
	quats = nullptr;

	auto normal = new VertexBufferAttribute();
	normal->array = reinterpret_cast<float*>(tangents);
	normal->attribute = filament::VertexAttribute::TANGENTS;
	normal->attributeType = filament::VertexBuffer::AttributeType::SHORT4;
	normal->itemSize = 4;
	normal->count = vertexCount;
	normal->normalized = true;
	attributes.insert({ filament::VertexAttribute::TANGENTS, normal });

	BufferGeometry::create();
}

void BoxGeometry::buildPlane(std::string u, std::string v, std::string w, float udir, float vdir, float width, float height, float depth, int gridX, int gridY, int materialIndex)
{
	float segmentWidth = width / gridX;
	float segmentHeight = height / gridY;

	float widthHalf = width / 2;
	float heightHalf = height / 2;
	float depthHalf = depth / 2;

	int gridX1 = gridX + 1;
	int gridY1 = gridY + 1;

	int vertexCounter = 0;
	int groupCount = 0;

	std::unordered_map<std::string, float> vector;

	// generate vertices, normals and uvs
	for (float iy = 0; iy < gridY1; iy++)
	{
		float y = iy * segmentHeight - heightHalf;

		for (float ix = 0; ix < gridX1; ix++)
		{
			float x = ix * segmentWidth - widthHalf;

			// set values to correct vector component
			vector.clear();
			vector.insert({ u, x * udir });
			vector.insert({ v, y * vdir });
			vector.insert({ w, depthHalf });

			// now apply vector to vertex buffer
			this->vertices.push_back(filament::math::float3(vector.at("x"), vector.at("y"), vector.at("z")));

			// set values to correct vector component
			vector.clear();
			vector.insert({ u, 0 });
			vector.insert({ v, 0 });
			vector.insert({ w, depth > 0 ? 1 : -1 });

			// now apply vector to normal buffer
			this->normals.push_back(filament::math::float3(vector.at("x"), vector.at("y"), vector.at("z")));

			// uvs
			this->uvs.push_back(filament::math::float2(ix / gridX, 1 - (iy / gridY)));

			// counters
			vertexCounter += 1;
		}
	}

	// indices

	// 1. you need three indices to draw a single face
	// 2. a single segment consists of two faces
	// 3. so we need to generate six (2*3) indices per segment
	for (int iy = 0; iy < gridY; iy++)
	{
		for (int ix = 0; ix < gridX; ix++)
		{
			int a = numberOfVertices + ix + gridX1 * iy;
			int b = numberOfVertices + ix + gridX1 * (iy + 1);
			int c = numberOfVertices + (ix + 1) + gridX1 * (iy + 1);
			int d = numberOfVertices + (ix + 1) + gridX1 * iy;

			// faces
			this->triangles.push_back(filament::math::uint3(a, b, d));
			this->triangles.push_back(filament::math::uint3(b, c, d));

			// increase counter
			groupCount += 6;
		}
	}

	// add a group to the geometry. this will ensure multi material support
	this->addGroup(groupStart, groupCount, materialIndex);

	// calculate new start value for groups
	groupStart += groupCount;

	// update total number of vertices
	numberOfVertices += vertexCounter;
}
