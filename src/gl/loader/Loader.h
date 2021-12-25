#ifndef GL_LOADER_LOADER_H
#define GL_LOADER_LOADER_H
#include "../object/Mesh.h"
#include "../Context.h"

namespace gl::loader
{
	class Loader
	{
	public:
		Loader(Context* context);
		virtual ~Loader();
		gl::object::Mesh* load();

	protected:
		Context* context;
	};
}

#endif