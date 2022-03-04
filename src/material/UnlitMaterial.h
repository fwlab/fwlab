#ifndef FWLAB_MATERIAL_UNLIT_MATERIAL_H
#define FWLAB_MATERIAL_UNLIT_MATERIAL_H
#include <math/vec4.h>
#include "../texture/Texture.h"
#include "Material.h"

namespace fwlab::material
{
	class UnlitMaterial : public Material
	{
	public:
		UnlitMaterial();
		virtual ~UnlitMaterial();
		filament::math::float4 getBaseColor() const noexcept;
		void setBaseColor(filament::math::float4 baseColor) noexcept;
		filament::math::float4 getEmissive() const noexcept;
		void setEmissive(filament::math::float4 emissive) noexcept;
		filament::math::float4 getPostLightingColor() const noexcept;				  // not implemented
		void setPostLightingColor(filament::math::float4 postLightingColor) noexcept; // not implemented
		gl::texture::Texture* getMap() const noexcept;
		void setMap(gl::texture::Texture* texture) noexcept;

	protected:
		filament::math::float4 baseColor = { 1, 1, 1, 1 };
		filament::math::float4 emissive = { 0, 0, 0, 0 };
		filament::math::float4 postLightingColor = { 0, 0, 0, 0 };
		bool enableMap = false;
		gl::texture::Texture* map = nullptr;
	};
}

#endif