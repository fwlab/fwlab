#ifndef BOX_GEOMETRY_H
#define BOX_GEOMETRY_H
#include <vector>
#include "../core/buffer_geometry.h"
#include "../core/buffer_attribute.h"
#include "../math/vector3.h"

template <typename T>
class BoxGeometry : public BufferGeometry<T>
{
public:
	explicit BoxGeometry(
		T width = 1,
		T height = 1,
		T depth = 1,
		int widthSegments = 1,
		int heightSegments = 1,
		int depthSegments = 1);
	virtual ~BoxGeometry();
	static BoxGeometry<T>* fromJSON(BoxBufferGeometryJSON<T>* data);
	std::string type;
	BoxGeometryParameters<T>* parameters;

private:
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<uint32_t> indices;
	int numberOfVertices;
	int groupStart;
	void buildPlane(std::string u, std::string v, std::string w, T udir, T vdir, T width, T height, T depth, int gridX, int gridY, int materialIndex);
};

template <typename T>
using BoxBufferGeoemtry = BoxGeometry<T>;

#endif