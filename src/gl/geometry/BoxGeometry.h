#ifndef GL_GEOMETRY_BOX_GEOMETRY_H
#define GL_GEOMETRY_BOX_GEOMETRY_H
#include <stdint.h>
#include <string>
#include <vector>
#include <math/vec2.h>
#include <math/vec3.h>
#include "../Context.h"
#include "../core/BufferGeometry.h"

namespace gl::geometry
{
	using gl::core::BufferGeometry;

	class BoxGeometry : public BufferGeometry
	{
	public:
		BoxGeometry(Context* context);
		virtual ~BoxGeometry();
		void create(float width = 1, float height = 1, float depth = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1, uint16_t depthSegments = 1);

	private:
		std::vector<filament::math::float3> vertices;
		std::vector<filament::math::float3> normals;
		std::vector<filament::math::float2> uvs;
		std::vector<filament::math::uint3> triangles;
		filament::math::short4* tangents = nullptr;
		uint32_t numberOfVertices = 0;
		uint32_t groupStart = 0;
		void buildPlane(std::string u, std::string v, std::string w, float udir, float vdir, float width, float height, float depth, int gridX, int gridY, int materialIndex);
	};
}

#endif