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

// texture
size_t Texture::computeTextureDataSize(filament::Texture::Format format, filament::Texture::Type type, size_t stride,
	size_t height, size_t alignment) noexcept
{
	return filament::Texture::computeTextureDataSize(format, type, stride, height, alignment);
}

void Texture::generateMipmaps() const noexcept
{
	texture->generateMipmaps(*engine);
}

void Texture::generatePrefilterMipmap(filament::Texture::PixelBufferDescriptor&& buffer,
	const filament::Texture::FaceOffsets& faceOffsets, filament::Texture::PrefilterOptions const* options)
{
	texture->generatePrefilterMipmap(*engine, std::move(buffer), faceOffsets, options);
}

size_t Texture::getDepth(size_t level) const noexcept
{
	return texture->getDepth(level);
}

filament::Texture::InternalFormat Texture::getFormat() const noexcept
{
	return texture->getFormat();
}

size_t Texture::getHeight(size_t level) const noexcept
{
	return texture->getHeight(level);
}

size_t Texture::getLevels() const noexcept
{
	return texture->getLevels();
}

filament::Texture::Sampler Texture::getTarget() const noexcept
{
	return texture->getTarget();
}

size_t Texture::getWidth(size_t level) const noexcept
{
	return texture->getWidth(level);
}

bool Texture::isTextureFormatSupported(filament::Texture::InternalFormat format) noexcept
{
	return filament::Texture::isTextureFormatSupported(*engine, format);
}

bool Texture::isTextureSwizzleSupported() noexcept
{
	return filament::Texture::isTextureSwizzleSupported(*engine);
}

void Texture::setExternalImage(void* image) noexcept
{
	texture->setExternalImage(*engine, image);
}

void Texture::setExternalImage(void* image, size_t plane) noexcept
{
	texture->setExternalImage(*engine, image, plane);
}

void Texture::setExternalStream(filament::Stream* stream) noexcept
{
	texture->setExternalStream(*engine, stream);
}

void Texture::setImage(size_t level, filament::Texture::PixelBufferDescriptor&& buffer) const
{
	texture->setImage(*engine, level, std::move(buffer));
}

void Texture::setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
	filament::Texture::PixelBufferDescriptor&& buffer) const
{
	texture->setImage(*engine, level, xoffset, yoffset, width, height, std::move(buffer));
}

void Texture::setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t zoffset,
	uint32_t width, uint32_t height, uint32_t depth,
	filament::Texture::PixelBufferDescriptor&& buffer) const
{
	texture->setImage(*engine, level, xoffset, yoffset, zoffset, width, height, depth, std::move(buffer));
}

void Texture::setImage(size_t level,
	filament::Texture::PixelBufferDescriptor&& buffer, const filament::Texture::FaceOffsets& faceOffsets) const
{
	texture->setImage(*engine, level, std::move(buffer), faceOffsets);
}