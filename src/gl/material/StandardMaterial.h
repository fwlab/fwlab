#ifndef GL_MATERIAL_STANDARD_MATERIAL_H
#define GL_MATERIAL_STANDARD_MATERIAL_H
#include <math/vec3.h>
#include <math/vec4.h>
#include "../Context.h"
#include "Material.h"

namespace gl::material
{
	class StandardMaterial : public Material {
	public:
		StandardMaterial(Context* context);
		virtual ~StandardMaterial();
		void create() override;
		filament::math::float4 baseColor = { 1, 1, 1, 1 }; // Pre-multiplied linear RGB, Non-metals: [0.04..0.94], Metals: [0.66..1.0]
		float metallic = 1; // Should be 0 or 1
		float roughness = 0.5;
		float reflectance = 0.5; // Prefer values > 0.35
		filament::math::float3 sheenColor = { 0, 0, 0 }; // Linear RGB
		float sheenRoughness = 1;
		float clearCoat = 0; // Should be 0 or 1
		float clearCoatRoughness = 0.5;
		float anisotropy = 0; // Anisotropy is in the tangent direction when this value is positive
		filament::math::float3 anisotropyDirection = { 0, 1, 0 }; // Linear RGB, encodes a direction vector in tangent space
		float ambientOcclusion = 0;
		// filament::math::float3 normal; // Linear RGB, encodes a direction vector in tangent space
		// filament::math::float3 bentNormal; // Linear RGB, encodes a direction vector in tangent space
		// filament::math::float3 clearCoatNormal; // Linear RGB, encodes a direction vector in tangent space
		filament::math::float4 emissive = { 0, 0, 0, 0 }; // Linear RGB intensity in nits, alpha encodes the exposure weight
		// filament::math::float4 postLightingColor; // Pre-multiplied linear RGB
		// float ior = 0.3; // Optional, usually deduced from the reflectance
		// float transmission;
		// float absorption;
		// float microThickness;
		// float thickness;
	};
}

#endif