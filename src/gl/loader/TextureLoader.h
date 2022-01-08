#ifndef GL_LOADER_TEXTURE_LOADER_H
#define GL_LOADER_TEXTURE_LOADER_H
#include "Loader.h"
#include "ImageLoader.h"

namespace gl::loader
{
	class TextureLoader : public Loader
	{
	public:
		TextureLoader() = default;
		virtual ~TextureLoader() = default;
	};
}

#endif