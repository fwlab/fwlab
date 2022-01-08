#ifndef GL_LOADER_IMAGE_LOADER_H
#define GL_LOADER_IMAGE_LOADER_H
#include <stdint.h>
#include "Loader.h"

namespace gl::loader
{
	class ImageLoader : public Loader
	{
	public:
		ImageLoader() = default;
		virtual ~ImageLoader() = default;
		uint8_t* load(char* filename, int* width, int* height, int* channels, int req_channels);
		uint8_t* load(uint8_t* buffer, size_t size, int* width, int* height, int* channels, int req_channels);
	};
}

#endif