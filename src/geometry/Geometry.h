#ifndef FWLAB_GEOMETRY_GEOMETRY_H
#define FWLAB_GEOMETRY_GEOMETRY_H
#include <filament/Box.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <math/vec3.h>

namespace fwlab::geometry
{
	class Geometry
	{
	public:
		Geometry() = default;
		virtual ~Geometry();
		filament::VertexBuffer* getVertexBuffer();
		filament::IndexBuffer* getIndexBuffer();
		filament::Box* getBoundingBox();

	protected:
		void createVertexBuffer();
		void createIndexBuffer();
		void computeBoundingBox();
		filament::VertexBuffer* vertexBuffer = nullptr;
		filament::IndexBuffer* indexBuffer = nullptr;
		filament::Box* boundingBox = nullptr;
		float* vertices = nullptr;
		uint32_t verticesSize = 0;
		float* normals = nullptr;
		uint32_t normalsSize = 0;
		float* uvs = nullptr;
		uint32_t uvsSize = 0;
		uint32_t* indices = nullptr;
		uint32_t indicesSize = 0;
		filament::math::short4* tangents = nullptr;
		uint32_t tangentsSize = 0;

	private:
		filament::math::float3* min = nullptr;
		filament::math::float3* max = nullptr;
	};
}

#endif