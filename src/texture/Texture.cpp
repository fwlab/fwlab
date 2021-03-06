#include "../utils/ImageUtils.h"
#include "Texture.h"
#include "../context/context.h"

namespace fwlab::texture
{
	Texture::Texture(uint32_t width, uint32_t height, filament::Texture::Format format) : Texture(width, height, utils::ImageUtils::textureFormatToInternalFormat(format))
	{
	}

	Texture::Texture(uint32_t width, uint32_t height, filament::Texture::InternalFormat format)
	{
		auto engine = app->getEngine();

		texture = filament::Texture::Builder()
					  .width(width)
					  .height(height)
					  .levels(0xff)
					  .format(format)
					  .build(*engine);

		sampler = new filament::TextureSampler();
	}

	Texture::~Texture()
	{
		if (texture)
		{
			app->getEngine()->destroy(texture);
			texture = nullptr;
		}
		if (sampler)
		{
			delete sampler;
			sampler = nullptr;
		}
	}

	filament::Texture *Texture::getTexture() const
	{
		return texture;
	}

	void Texture::setTexture(filament::Texture *texture)
	{
		this->texture = texture;
	}

	filament::TextureSampler *Texture::getSampler() const
	{
		return sampler;
	}

	void Texture::setSampler(filament::TextureSampler *sampler)
	{
		this->sampler = sampler;
	}

	// texture
	size_t Texture::computeTextureDataSize(filament::Texture::Format format, filament::Texture::Type type, size_t stride,
										   size_t height, size_t alignment)
	{
		return filament::Texture::computeTextureDataSize(format, type, stride, height, alignment);
	}

	void Texture::generateMipmaps() const
	{
		auto engine = app->getEngine();

		texture->generateMipmaps(*engine);
	}

	void Texture::generatePrefilterMipmap(filament::Texture::PixelBufferDescriptor &&buffer,
										  const filament::Texture::FaceOffsets &faceOffsets, filament::Texture::PrefilterOptions const *options)
	{
		auto engine = app->getEngine();

		texture->generatePrefilterMipmap(*engine, std::move(buffer), faceOffsets, options);
	}

	size_t Texture::getDepth(size_t level) const
	{
		return texture->getDepth(level);
	}

	filament::Texture::InternalFormat Texture::getFormat() const
	{
		return texture->getFormat();
	}

	size_t Texture::getHeight(size_t level) const
	{
		return texture->getHeight(level);
	}

	size_t Texture::getLevels() const
	{
		return texture->getLevels();
	}

	filament::Texture::Sampler Texture::getTarget() const
	{
		return texture->getTarget();
	}

	size_t Texture::getWidth(size_t level) const
	{
		return texture->getWidth(level);
	}

	bool Texture::isTextureFormatSupported(filament::Texture::InternalFormat format)
	{
		auto engine = app->getEngine();

		return filament::Texture::isTextureFormatSupported(*engine, format);
	}

	bool Texture::isTextureSwizzleSupported()
	{
		auto engine = app->getEngine();

		return filament::Texture::isTextureSwizzleSupported(*engine);
	}

	void Texture::setExternalImage(void *image)
	{
		auto engine = app->getEngine();

		texture->setExternalImage(*engine, image);
	}

	void Texture::setExternalImage(void *image, size_t plane)
	{
		auto engine = app->getEngine();

		texture->setExternalImage(*engine, image, plane);
	}

	void Texture::setExternalStream(filament::Stream *stream)
	{
		auto engine = app->getEngine();

		texture->setExternalStream(*engine, stream);
	}

	void Texture::setImage(size_t level, filament::Texture::PixelBufferDescriptor &&buffer) const
	{
		auto engine = app->getEngine();

		texture->setImage(*engine, level, std::move(buffer));
	}

	void Texture::setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
						   filament::Texture::PixelBufferDescriptor &&buffer) const
	{
		auto engine = app->getEngine();

		texture->setImage(*engine, level, xoffset, yoffset, width, height, std::move(buffer));
	}

	void Texture::setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t zoffset,
						   uint32_t width, uint32_t height, uint32_t depth,
						   filament::Texture::PixelBufferDescriptor &&buffer) const
	{
		auto engine = app->getEngine();

		texture->setImage(*engine, level, xoffset, yoffset, zoffset, width, height, depth, std::move(buffer));
	}

	void Texture::setImage(size_t level,
						   filament::Texture::PixelBufferDescriptor &&buffer, const filament::Texture::FaceOffsets &faceOffsets) const
	{
		auto engine = app->getEngine();

		texture->setImage(*engine, level, std::move(buffer), faceOffsets);
	}

	// sampler
	float Texture::getAnisotropy() const
	{
		return sampler->getAnisotropy();
	}

	filament::TextureSampler::CompareFunc Texture::getCompareFunc() const
	{
		return sampler->getCompareFunc();
	}

	filament::TextureSampler::CompareMode Texture::getCompareMode() const
	{
		return sampler->getCompareMode();
	}

	filament::TextureSampler::MagFilter Texture::getMagFilter() const
	{
		return sampler->getMagFilter();
	}

	filament::TextureSampler::MinFilter Texture::getMinFilter() const
	{
		return sampler->getMinFilter();
	}

	filament::backend::SamplerParams Texture::getSamplerParams() const
	{
		return sampler->getSamplerParams();
	}

	filament::TextureSampler::WrapMode Texture::getWrapModeR() const
	{
		return sampler->getWrapModeR();
	}

	filament::TextureSampler::WrapMode Texture::getWrapModeS() const
	{
		return sampler->getWrapModeS();
	}

	filament::TextureSampler::WrapMode Texture::getWrapModeT() const
	{
		return sampler->getWrapModeT();
	}

	void Texture::setAnisotropy(float anisotropy)
	{
		return sampler->setAnisotropy(anisotropy);
	}

	void Texture::setCompareMode(filament::TextureSampler::CompareMode mode, filament::TextureSampler::CompareFunc func)
	{
		return sampler->setCompareMode(mode, func);
	}

	void Texture::setMagFilter(filament::TextureSampler::MagFilter v)
	{
		return sampler->setMagFilter(v);
	}

	void Texture::setMinFilter(filament::TextureSampler::MinFilter v)
	{
		return sampler->setMinFilter(v);
	}

	void Texture::setWrapModeR(filament::TextureSampler::WrapMode v)
	{
		return sampler->setWrapModeR(v);
	}

	void Texture::setWrapModeS(filament::TextureSampler::WrapMode v)
	{
		return sampler->setWrapModeS(v);
	}

	void Texture::setWrapModeT(filament::TextureSampler::WrapMode v)
	{
		return sampler->setWrapModeT(v);
	}
}