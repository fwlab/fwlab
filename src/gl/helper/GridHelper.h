#ifndef GL_HELPER_GRID_HELPER_H
#define GL_HELPER_GRID_HELPER_H
#include "../core/BufferGeometry.h"
#include "../object/Mesh.h"
#include "../material/StandardMaterial.h"

class GridHelper : gl::object::Mesh
{
public:
	GridHelper();
	virtual ~GridHelper();
};

#endif