#ifndef FWLAB_LOADER_FILAMESH_LOADER_H
#define FWLAB_LOADER_FILAMESH_LOADER_H
#include <filament/MaterialInstance.h>
#include <filameshio/MeshReader.h>
#include "../object/Mesh.h"

namespace fwlab::loader
{
	class FilameshLoader
	{
	public:
		FilameshLoader() = default;
		virtual ~FilameshLoader() = default;
		object::Mesh* load(void const* data);
		object::Mesh* load(const ::utils::Path& path, filamesh::MeshReader::MaterialRegistry materials);
	};
}

#endif