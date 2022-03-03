#ifndef GL_LOADER_TEXTURE_LOADER_H
#define GL_LOADER_TEXTURE_LOADER_H
#include <filament/Texture.h>
#include "Loader.h"
#include "../texture/Texture.h"

namespace gl::loader
{
	class TextureLoader : public Loader
	{
	public:
		TextureLoader() = default;
		virtual ~TextureLoader() = default;
		gl::texture::Texture *load(const char *filename, filament::Texture::Format format = filament::Texture::Format::RGB);
		gl::texture::Texture *load(const char *filename, filament::Texture::InternalFormat format);
		gl::texture::Texture *load(uint8_t *buffer, size_t size, filament::Texture::Format format = filament::Texture::Format::RGB);
		gl::texture::Texture *load(uint8_t *buffer, size_t size, filament::Texture::InternalFormat format);
	};
}

#endif