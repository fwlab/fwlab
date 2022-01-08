#ifndef GL_MATERIAL_UNLIT_MATERIAL_H
#define GL_MATERIAL_UNLIT_MATERIAL_H
#include <math/vec4.h>
#include "Material.h"

namespace gl::material
{
	class UnlitMaterial : public Material {
	public:
		UnlitMaterial();
		virtual ~UnlitMaterial();
		filament::math::float4 getBaseColor() const;
		void setBaseColor(filament::math::float4 baseColor);
		filament::math::float4 getEmissive() const;
		void setEmissive(filament::math::float4 baseColor);
		filament::math::float4 getPostLightingColor() const;
		void setPostLightingColor(filament::math::float4 baseColor);

	protected:
		filament::math::float4 baseColor = { 1, 1, 1, 1 };
		filament::math::float4 emissive = { 0, 0, 0, 0 };
		filament::math::float4 postLightingColor = { 0, 0, 0, 0 };
	};
}

#endif