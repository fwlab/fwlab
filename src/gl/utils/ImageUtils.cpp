#include "ImageUtils.h"

using namespace gl::utils;

uint8_t ImageUtils::getTextureInternalFormatChannels(filament::Texture::InternalFormat format)
{
	switch (format)
	{
	case filament::Texture::InternalFormat::RGBA8:
		return 4;
	case filament::Texture::InternalFormat::RGB8:
		return 3;
	default:
		throw "ImageUtils::getTextureInternalFormatChannels: unsupported format";
	}
}

filament::Texture::Format ImageUtils::textureInternalFormatToFormat(filament::Texture::InternalFormat format)
{
	switch (format)
	{
	case filament::Texture::InternalFormat::RGBA8:
		return filament::Texture::Format::RGBA;
	case filament::Texture::InternalFormat::RGB8:
		return filament::Texture::Format::RGB;
	default:
		throw "ImageUtils::getTextureInternalFormatChannels: unsupported format";
	}
}