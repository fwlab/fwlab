#ifndef GL_TEXTURE_TEXTURE_H
#define GL_TEXTURE_TEXTURE_H
#include <stdint.h>
#include <filament/Engine.h>
#include <filament/Texture.h>

namespace gl::texture
{
	class Texture
	{
	public:
		Texture(uint32_t width, uint32_t height, filament::Texture::InternalFormat format = filament::Texture::InternalFormat::RGB8);
		virtual ~Texture();
		filament::Texture* getTexture() const noexcept;

		// texture
		static size_t computeTextureDataSize(filament::Texture::Format format, filament::Texture::Type type, size_t stride,
			size_t height, size_t alignment) noexcept;
		void generateMipmaps() const noexcept;
		void generatePrefilterMipmap(filament::Texture::PixelBufferDescriptor&& buffer,
			const filament::Texture::FaceOffsets& faceOffsets, filament::Texture::PrefilterOptions const* options);
		size_t getDepth(size_t level) const noexcept;
		filament::Texture::InternalFormat getFormat() const noexcept;
		size_t getHeight(size_t level) const noexcept;
		size_t getLevels() const noexcept;
		filament::Texture::Sampler getTarget() const noexcept;
		size_t getWidth(size_t level) const noexcept;
		static bool isTextureFormatSupported(filament::Texture::InternalFormat format) noexcept;
		static bool isTextureSwizzleSupported() noexcept;
		void setExternalImage(void* image) noexcept;
		void setExternalImage(void* image, size_t plane) noexcept;
		void setExternalStream(filament::Stream* stream) noexcept;
		void setImage(size_t level,
			filament::Texture::PixelBufferDescriptor&& buffer) const;
		void setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
			filament::Texture::PixelBufferDescriptor&& buffer) const;
		void setImage(size_t level, uint32_t xoffset, uint32_t yoffset, uint32_t zoffset,
			uint32_t width, uint32_t height, uint32_t depth,
			filament::Texture::PixelBufferDescriptor&& buffer) const;
		void setImage(size_t level, filament::Texture::PixelBufferDescriptor&& buffer, const filament::Texture::FaceOffsets& faceOffsets) const;

	private:
		filament::Texture* texture = nullptr;
	};
}

#endif