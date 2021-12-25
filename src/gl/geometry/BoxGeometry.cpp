#include <cmath>
#include "BoxGeometry.h"

using namespace gl::geometry;

BoxGeometry::BoxGeometry(Context* context) : Geometry(context)
{
}

BoxGeometry::~BoxGeometry()
{
}

BoxGeometry* create(float width, float height, float depth, uint16_t widthSegments, uint16_t heightSegments, uint16_t depthSegments)
{
	// segments
	widthSegments = std::floor(widthSegments);
	heightSegments = std::floor(heightSegments);
	depthSegments = std::floor(depthSegments);

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

	// build geometry
	this->setIndex(indices);
	this->setAttribute("position", new Float32BufferAttribute(this->vertices, 3));
	this->setAttribute("normal", new Float32BufferAttribute(this->normals, 3));
	this->setAttribute("uv", new Float32BufferAttribute(this->uvs, 2));
}

template <typename T>
void BoxGeometry<T>::buildPlane(std::string u, std::string v, std::string w, T udir, T vdir, T width, T height, T depth, int gridX, int gridY, int materialIndex)
{
	T segmentWidth = width / gridX;
	T segmentHeight = height / gridY;

	T widthHalf = width / 2;
	T heightHalf = height / 2;
	T depthHalf = depth / 2;

	int gridX1 = gridX + 1;
	int gridY1 = gridY + 1;

	int vertexCounter = 0;
	int groupCount = 0;

	Vector3<T>* vector = new Vector3<T>();

	// generate vertices, normals and uvs
	for (int iy = 0; iy < gridY1; iy++)
	{
		T y = iy * segmentHeight - heightHalf;

		for (int ix = 0; ix < gridX1; ix++)
		{
			int x = ix * segmentWidth - widthHalf;

			// set values to correct vector component
			(*vector)[u] = x * udir;
			(*vector)[v] = y * vdir;
			(*vector)[w] = depthHalf;

			// now apply vector to vertex buffer
			this->vertices.push_back(vector->x);
			this->vertices.push_back(vector->y);
			this->vertices.push_back(vector->z);

			// set values to correct vector component
			(*vector)[u] = 0;
			(*vector)[v] = 0;
			(*vector)[w] = depth > 0 ? 1 : -1;

			// now apply vector to normal buffer
			this->normals.push_back(vector->x);
			this->normals.push_back(vector->y);
			this->normals.push_back(vector->z);

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
