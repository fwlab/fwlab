#ifndef GL_UTILS_IMAGE_UTILS_H
#define GL_UTILS_IMAGE_UTILS_H
#include <stdint.h>
#include <filament/Texture.h>

namespace gl::utils
{
	class ImageUtils
	{
	public:
		static uint8_t getTextureInternalFormatChannels(filament::Texture::InternalFormat format);
		static filament::Texture::Format textureInternalFormatToFormat(filament::Texture::InternalFormat format);
		static filament::Texture::InternalFormat textureFormatToInternalFormat(filament::Texture::Format format);
	};
}

#endif