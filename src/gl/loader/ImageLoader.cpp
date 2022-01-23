#include <stb_image.h>
#include "ImageLoader.h"

using namespace gl::loader;

uint8_t *ImageLoader::load(const char *filename, int *width, int *height, int *channels, int req_channels)
{
	return stbi_load(filename, width, height, channels, req_channels);
}

uint8_t *ImageLoader::load(uint8_t *buffer, size_t size, int *width, int *height, int *channels, int req_channels)
{
	return stbi_load_from_memory(buffer, size, width, height, channels, req_channels);
}