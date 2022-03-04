#ifndef FWLAB_TEXTURE_TEXTURE_H
#define FWLAB_TEXTURE_TEXTURE_H
#include <stdint.h>
#include <filament/Engine.h>
#include <filament/Texture.h>
#include <filament/TextureSampler.h>
#include <backend/DriverEnums.h>

namespace fwlab::texture
{
	class Texture
	{
	public:
		Texture(uint32_t width, uint32_t height, filament::Texture::Format = filament::Texture::Format::RGB);
		Texture(uint32_t width, uint32_t height, filament::Texture::InternalFormat format);
		virtual ~Texture();
		filament::Texture *getTexture() const;
		void setTexture(filament::Texture *texture);
		filament::TextureSampler *getSampler() const;
		void setSampler(filament::TextureSampler *sampler);

		// texture
		static size_t computeTextureDataSize(filament::Texture::Format format, filament::Texture::Type type, size_t stride,
											 size_t height, size_t alignment);
		void generateMipmaps() const;
		void generatePrefilterMipmap(filament::Texture::PixelBufferDescriptor &&buffer,
									 const filament::Texture::FaceOffsets &faceOffsets, filament::Texture::PrefilterOptions const *options);
		size_t getDepth(size_t level) const;
		filament::Texture::InternalFormat getFormat() const;
		size_t getHeight(size_t level) const;
		size_t getLevels() const;
		filament::Texture::Sampler getTarget() const;
		size_t getWidth(size_t level) const;
		static bool isTextureFormatSupported(filament::Texture::InternalFormat format);
		static bool isTextureSwizzleSupported();
		void setExternalImage(void *image);
		void setExternalImage(void *image, size_t plane);
		void setExternalStream(filament::Stream *stream);
		void setImage(size_t level,
					  filament::Texture::PixelBufferDescriptor &&buffer) const;
		void setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
					  filament::Texture::PixelBufferDescriptor &&buffer) const;
		void setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t zoffset,
					  uint32_t width, uint32_t height, uint32_t depth,
					  filament::Texture::PixelBufferDescriptor &&buffer) const;
		void setImage(size_t level, filament::Texture::PixelBufferDescriptor &&buffer, const filament::Texture::FaceOffsets &faceOffsets) const;

		// sampler
		float getAnisotropy() const;
		filament::TextureSampler::CompareFunc getCompareFunc() const;
		filament::TextureSampler::CompareMode getCompareMode() const;
		filament::TextureSampler::MagFilter getMagFilter() const;
		filament::TextureSampler::MinFilter getMinFilter() const;
		filament::backend::SamplerParams getSamplerParams() const;
		filament::TextureSampler::WrapMode getWrapModeR() const;
		filament::TextureSampler::WrapMode getWrapModeS() const;
		filament::TextureSampler::WrapMode getWrapModeT() const;
		void setAnisotropy(float anisotropy);
		void setCompareMode(filament::TextureSampler::CompareMode mode, filament::TextureSampler::CompareFunc func = filament::TextureSampler::CompareFunc::LE);
		void setMagFilter(filament::TextureSampler::MagFilter v);
		void setMinFilter(filament::TextureSampler::MinFilter v);
		void setWrapModeR(filament::TextureSampler::WrapMode v);
		void setWrapModeS(filament::TextureSampler::WrapMode v);
		void setWrapModeT(filament::TextureSampler::WrapMode v);

	private:
		filament::Texture *texture = nullptr;
		filament::TextureSampler *sampler = nullptr;
	};
}

#endif