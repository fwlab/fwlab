#ifndef FWLAB_LOADER_TEXTURE_LOADER_H
#define FWLAB_LOADER_TEXTURE_LOADER_H
#include <filament/Texture.h>
#include "Loader.h"
#include "../texture/Texture.h"

namespace fwlab::loader
{
	class TextureLoader : public Loader
	{
	public:
		TextureLoader() = default;
		virtual ~TextureLoader() = default;
		texture::Texture* load(const char* filename, filament::Texture::Format format = filament::Texture::Format::RGB);
		texture::Texture* load(const char* filename, filament::Texture::InternalFormat format);
		texture::Texture* load(uint8_t* buffer, size_t size, filament::Texture::Format format = filament::Texture::Format::RGB);
		texture::Texture* load(uint8_t* buffer, size_t size, filament::Texture::InternalFormat format);
	};
}

#endif