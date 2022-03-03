#ifndef GL_LOADER_MESH_LOADER_H
#define GL_LOADER_MESH_LOADER_H
#include <utils/Path.h>
#include "Loader.h"

namespace gl::loader
{
	class MeshLoader : public Loader
	{
	public:
		MeshLoader() = default;
		virtual ~MeshLoader() override = default;
		virtual gl::object::Mesh *load(const utils::Path &path);
	};
}

#endif