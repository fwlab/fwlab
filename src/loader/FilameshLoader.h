#ifndef FWLAB_LOADER_FILAMESH_LOADER_H
#define FWLAB_LOADER_FILAMESH_LOADER_H
#include <filament/MaterialInstance.h>
#include <filameshio/MeshReader.h>
#include "MeshLoader.h"

namespace fwlab::loader
{
	class FilameshLoader : public MeshLoader
	{
	public:
		FilameshLoader() = default;
		virtual ~FilameshLoader() = default;
		object::Mesh* load(void const* data);
		object::Mesh* load(const ::utils::Path& path, filamesh::MeshReader::MaterialRegistry materials);
	};
}

#endif