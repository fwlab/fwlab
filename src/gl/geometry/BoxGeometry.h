#ifndef GL_GEOMETRY_BOX_GEOMETRY_H
#define GL_GEOMETRY_BOX_GEOMETRY_H
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
		BoxGeometry* create(float width = 1, float height = 1, float depth = 1, uint16_t widthSegments = 1, uint16_t heightSegments = 1, uint16_t depthSegments = 1);

	private:
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<float> uvs;
		std::vector<uint32_t> indices;
		int numberOfVertices;
		int groupStart;
		void buildPlane(std::string u, std::string v, std::string w, T udir, T vdir, T width, T height, T depth, int gridX, int gridY, int materialIndex);
	};
}

#endif