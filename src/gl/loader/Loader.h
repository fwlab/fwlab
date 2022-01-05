#ifndef GL_LOADER_LOADER_H
#define GL_LOADER_LOADER_H
#include "../object/Mesh.h"

namespace gl::loader
{
	class Loader
	{
	public:
		Loader();
		virtual ~Loader();
		gl::object::Mesh* load();
	};
}

#endif