#include <stb_image.h>
#include "ImageLoader.h"
#include "../utils/ImageUtils.h"
#include "TextureLoader.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::texture;
using namespace gl::loader;
using namespace gl::utils;

static ImageLoader imageLoader;

gl::texture::Texture* TextureLoader::load(const char* filename, filament::Texture::Format format)
{
	return load(filename, ImageUtils::textureFormatToInternalFormat(format));
}

gl::texture::Texture* TextureLoader::load(const char* filename, filament::Texture::InternalFormat format)
{
	auto req_channels = ImageUtils::getTextureInternalFormatChannels(format);
	auto text_format = ImageUtils::textureInternalFormatToFormat(format);

	int width, height, channels;
	auto data = imageLoader.load(filename, &width, &height, &channels, req_channels);
	// TODO: channels < req_channels, may overflow
	auto dataSize = size_t(width * height * req_channels);

	auto texture = new Texture(width, height, format);
	filament::Texture::PixelBufferDescriptor buffer(data, dataSize, text_format, filament::Texture::Type::UBYTE,
		(filament::Texture::PixelBufferDescriptor::Callback)&stbi_image_free);
	texture->setImage(0, std::move(buffer));
	texture->generateMipmaps();

	return texture;
}

gl::texture::Texture* TextureLoader::load(uint8_t* buffer, size_t size, filament::Texture::Format format)
{
	return load(buffer, size, ImageUtils::textureFormatToInternalFormat(format));
}

gl::texture::Texture* TextureLoader::load(uint8_t* buffer, size_t size, filament::Texture::InternalFormat format)
{
	auto req_channels = ImageUtils::getTextureInternalFormatChannels(format);
	auto text_format = ImageUtils::textureInternalFormatToFormat(format);

	int width, height, channels;
	auto data = imageLoader.load(buffer, size, &width, &height, &channels, req_channels);
	auto dataSize = size_t(width * height * channels);

	auto texture = new Texture(width, height);
	filament::Texture::PixelBufferDescriptor bufferDescriptor(data, dataSize, text_format, filament::Texture::Type::UBYTE,
		(filament::Texture::PixelBufferDescriptor::Callback)&stbi_image_free);
	texture->setImage(0, std::move(bufferDescriptor));
	texture->generateMipmaps();

	return texture;
}