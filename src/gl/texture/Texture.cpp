#include "Texture.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::texture;

Texture::Texture(uint32_t width, uint32_t height, filament::Texture::InternalFormat format)
{
	texture = filament::Texture::Builder()
		.width(width)
		.height(height)
		.levels(0xff)
		.format(format)
		.build(*engine);
}

Texture::~Texture()
{
	if (texture)
	{
		engine->destroy(texture);
	}
}

filament::Texture* Texture::getTexture() const noexcept
{
	return texture;
}