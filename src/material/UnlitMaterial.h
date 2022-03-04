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
		filament::math::float4 getBaseColor() const;
		void setBaseColor(filament::math::float4 baseColor);
		filament::math::float4 getEmissive() const;
		void setEmissive(filament::math::float4 emissive);
		filament::math::float4 getPostLightingColor() const;				 // not implemented
		void setPostLightingColor(filament::math::float4 postLightingColor); // not implemented
		texture::Texture *getMap() const;
		void setMap(texture::Texture *texture);

	protected:
		filament::math::float4 baseColor = {1, 1, 1, 1};
		filament::math::float4 emissive = {0, 0, 0, 0};
		filament::math::float4 postLightingColor = {0, 0, 0, 0};
		bool enableMap = false;
		texture::Texture *map = nullptr;
	};
}

#endif