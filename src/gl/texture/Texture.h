#ifndef GL_TEXTURE_TEXTURE_H
#define GL_TEXTURE_TEXTURE_H
#include <stdint.h>
#include <filament/Texture.h>

namespace gl::texture
{
	class Texture
	{
	public:
		Texture(uint32_t width, uint32_t height, filament::Texture::InternalFormat format = filament::Texture::InternalFormat::RGBA32F);
		virtual ~Texture();
		filament::Texture* getTexture() const noexcept;

	private:
		filament::Texture* texture = nullptr;
	};
}

#endif