#include <cmath>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include "../utils/Logger.h"
#include "BoxGeometry.h"

using namespace gl::core;
using namespace gl::geometry;
using namespace gl::utils;

BoxGeometry::BoxGeometry(Context* context) : BufferGeometry(context)
{
}

BoxGeometry::~BoxGeometry()
{
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

	// debug
	Logger logger;
	logger << "vertices: " << vertices << "\n";
	logger << "normals: " << normals << "\n";
	logger << "uvs: " << uvs << "\n";
	logger << "indices: " << indices << "\n";

	uint32_t verticesSize = vertices.size();
	float* _vertices = new float[verticesSize];
	std::copy(vertices.begin(), vertices.end(), _vertices);
	vertices.clear();

	uint32_t normalsSize = normals.size();
	float* _normals = new float[normalsSize];
	std::copy(normals.begin(), normals.end(), _normals);
	normals.clear();

	uint32_t uvsSize = uvs.size();
	float* _uvs = new float[uvsSize];
	std::copy(uvs.begin(), uvs.end(), _uvs);
	uvs.clear();

	uint32_t indicesSize = indices.size();
	uint32_t* _indices = new uint32_t[indicesSize];
	std::copy(indices.begin(), indices.end(), _indices);
	indices.clear();

	// position
	auto position = new VertexBufferAttribute(context);
	position->array = _vertices;
	position->attribute = filament::VertexAttribute::POSITION;
	position->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	position->itemSize = 3;
	position->count = verticesSize / position->itemSize;
	attributes.insert({ filament::VertexAttribute::POSITION, position });

	// normal
	auto normal = new VertexBufferAttribute(context);
	normal->array = _normals;
	normal->attribute = filament::VertexAttribute::TANGENTS;
	normal->attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	normal->itemSize = 3;
	normal->count = normalsSize / normal->itemSize;
	attributes.insert({ filament::VertexAttribute::TANGENTS, normal });

	// uv
	auto uv = new VertexBufferAttribute(context);
	uv->array = _uvs;
	uv->attribute = filament::VertexAttribute::UV0;
	uv->attributeType = filament::VertexBuffer::AttributeType::FLOAT2;
	uv->itemSize = 2;
	uv->count = uvsSize / uv->itemSize;
	attributes.insert({ filament::VertexAttribute::UV0, uv });

	// index
	index = new IndexBufferAttribute(context);
	index->array = _indices;
	index->indexType = filament::IndexBuffer::IndexType::UINT;
	index->itemSize = 1;
	index->count = indicesSize / index->itemSize;

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
			this->vertices.push_back(vector.at("x"));
			this->vertices.push_back(vector.at("y"));
			this->vertices.push_back(vector.at("z"));

			// set values to correct vector component
			vector.clear();
			vector.insert({ u, 0 });
			vector.insert({ v, 0 });
			vector.insert({ w, depth > 0 ? 1 : -1 });

			// now apply vector to normal buffer
			this->normals.push_back(vector.at("x"));
			this->normals.push_back(vector.at("y"));
			this->normals.push_back(vector.at("z"));

			// uvs
			this->uvs.push_back(ix / gridX);
			this->uvs.push_back(1 - (iy / gridY));

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
			this->indices.push_back(a);
			this->indices.push_back(b);
			this->indices.push_back(d);
			this->indices.push_back(b);
			this->indices.push_back(c);
			this->indices.push_back(d);

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
