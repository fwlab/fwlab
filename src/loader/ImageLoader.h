#ifndef FWLAB_LOADER_IMAGE_LOADER_H
#define FWLAB_LOADER_IMAGE_LOADER_H
#include <stdint.h>

namespace fwlab::loader
{
	class ImageLoader
	{
	public:
		ImageLoader() = default;
		virtual ~ImageLoader() = default;
		uint8_t* load(const char* filename, int* width, int* height, int* channels, int req_channels);
		uint8_t* load(uint8_t* buffer, size_t size, int* width, int* height, int* channels, int req_channels);
	};
}

#endif