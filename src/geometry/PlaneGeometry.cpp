#include <vector>
#include <geometry/SurfaceOrientation.h>
#include "PlaneGeometry.h"

namespace fwlab::geometry
{
	PlaneGeometry::Builder* PlaneGeometry::Builder::setWidth(float width)
	{
		this->width = width;
		return this;
	}

	PlaneGeometry::Builder* PlaneGeometry::Builder::setHeight(float height)
	{
		this->height = height;
		return this;
	}

	PlaneGeometry::Builder* PlaneGeometry::Builder::setWidthSegments(uint16_t widthSegments)
	{
		this->widthSegments = widthSegments;
		return this;
	}

	PlaneGeometry::Builder* PlaneGeometry::Builder::setHeightSegments(uint16_t heightSegments)
	{
		this->heightSegments = heightSegments;
		return this;
	}

	PlaneGeometry* PlaneGeometry::Builder::build()
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
		std::vector<filament::math::float3> positions;
		std::vector<filament::math::float3> normals;
		std::vector<filament::math::float2> uvs;
		std::vector<filament::math::uint3> triangles;

		for (uint16_t iy = 0; iy < gridY1; iy++)
		{
			double y = iy * segment_height - height_half;

			for (uint16_t ix = 0; ix < gridX1; ix++)
			{
				uint32_t index = gridX1 * iy + ix;
				float x = ix * segment_width - width_half;

				filament::math::float3 vertex(x, -y, 0);
				positions.push_back(vertex);

				filament::math::float3 normal(0, 0, 1);
				normals.push_back(normal);

				filament::math::float2 uv(ix / gridX, 1 - (iy / gridY));
				uvs.push_back(uv);
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

				filament::math::uint3 t1(a, b, d);
				filament::math::uint3 t2(b, c, d);
				triangles.push_back(t1);
				triangles.push_back(t2);
			}
		}

		auto vertexCount = positions.size();

		auto quats = filament::geometry::SurfaceOrientation::Builder()
			.vertexCount(vertexCount)
			.positions(positions.data())
			.normals(normals.data())
			.uvs(uvs.data())
			.triangleCount(triangles.size())
			.triangles(triangles.data())
			.build();

		std::vector<filament::math::short4> tangents(vertexCount);
		quats->getQuats(tangents.data(), vertexCount, sizeof(filament::math::short4));
		delete quats;

		uint32_t verticesSize = vertexCount * 3;
		uint32_t normalsSize = vertexCount * 3;
		uint32_t uvsSize = vertexCount * 2;
		uint32_t indicesSize = triangles.size() * 3;
		uint32_t tangentsSize = vertexCount * 4;

		float* _vertices = new float[verticesSize];
		uint32_t i = 0;
		for (auto& position : positions)
		{
			_vertices[i++] = position.x;
			_vertices[i++] = position.y;
			_vertices[i++] = position.z;
		}

		float* _normals = new float[normalsSize];
		i = 0;
		for (auto& normal : normals)
		{
			_normals[i++] = normal.x;
			_normals[i++] = normal.y;
			_normals[i++] = normal.z;
		}

		float* _uvs = new float[uvsSize];
		i = 0;
		for (auto& uv : uvs)
		{
			_uvs[i++] = uv.x;
			_uvs[i++] = uv.y;
		}

		uint32_t* _indices = new uint32_t[indicesSize];
		i = 0;
		for (auto& triangle : triangles)
		{
			_indices[i++] = triangle.x;
			_indices[i++] = triangle.y;
			_indices[i++] = triangle.z;
		}

		filament::math::short4* _tangents = new filament::math::short4[tangentsSize];
		for (auto& tangent : tangents)
		{
			_tangents[i++] = tangent.x;
			_tangents[i++] = tangent.y;
			_tangents[i++] = tangent.z;
			_tangents[i++] = tangent.w;
		}

		auto geometry = new PlaneGeometry();
		geometry->vertices = _vertices;
		geometry->verticesSize = verticesSize;
		geometry->normals = _normals;
		geometry->normalsSize = normalsSize;
		geometry->uvs = _uvs;
		geometry->uvsSize = uvsSize;
		geometry->indices = _indices;
		geometry->indicesSize = indicesSize;
		geometry->tangents = _tangents;
		geometry->tangentsSize = tangentsSize;

		return geometry;
	}
}