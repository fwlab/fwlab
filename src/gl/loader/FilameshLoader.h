#ifndef GL_LOADER_FILAMESH_LOADER_H
#define GL_LOADER_FILAMESH_LOADER_H
#include <filament/MaterialInstance.h>
#include "Loader.h"

namespace gl::loader
{
	class FilameshLoader : public Loader
	{
	public:
		FilameshLoader();
		virtual ~FilameshLoader();
		gl::object::Mesh* load(void const* data, filament::MaterialInstance* defaultMaterial);
	};
}

#endif