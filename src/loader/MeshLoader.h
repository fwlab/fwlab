#ifndef FWLAB_LOADER_MESH_LOADER_H
#define FWLAB_LOADER_MESH_LOADER_H
#include <utils/Path.h>
#include "Loader.h"

namespace fwlab::loader
{
	class MeshLoader : public Loader
	{
	public:
		MeshLoader() = default;
		virtual ~MeshLoader() override = default;
		virtual object::Mesh* load(const ::utils::Path& path);
	};
}

#endif