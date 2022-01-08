#ifndef GL_LOADER_FILAMESH_LOADER_H
#define GL_LOADER_FILAMESH_LOADER_H
#include <filament/MaterialInstance.h>
#include <filameshio/MeshReader.h>
#include "MeshLoader.h"

namespace gl::loader
{
	class FilameshLoader : public gl::loader::MeshLoader
	{
	public:
		FilameshLoader() = default;
		virtual ~FilameshLoader() = default;
		gl::object::Mesh* load(void const* data);
		gl::object::Mesh* load(const utils::Path& path, filamesh::MeshReader::MaterialRegistry materials);
	};
}

#endif