#ifndef FWLAB_MATERIAL_STANDARD_MATERIAL_H
#define FWLAB_MATERIAL_STANDARD_MATERIAL_H
#include <math/vec3.h>
#include <math/vec4.h>
#include "../Context.h"
#include "Material.h"

/// <summary>
/// ±ê×¼²ÄÖÊ
/// </summary>
class StandardMaterial : public Material {
public:
	StandardMaterial(Context* context);
	virtual ~StandardMaterial();
	void create() override;
	filament::math::float4 baseColor = { 1, 1, 1, 1 };
	float metallic = 0;
	float roughness = 0.5;
	float reflectance = 1;
	filament::math::float3 sheenColor = { 0, 0, 0 };
	float sheenRoughness = 1;
	float clearCoat = 0;
	float clearCoatRoughness = 0.5;
	float anisotropy = 0;
	filament::math::float3 anisotropyDirection = { 0, 1, 0 };
	float ambientOcclusion = 0;
	// filament::math::float3 normal;
	// filament::math::float3 bentNormal;
	// filament::math::float3 clearCoatNormal;
	filament::math::float4 emissive = { 0, 0, 0, 0 };
	// filament::math::float4 postLightingColor;
	float ior = 0.3;
	// float transmission;
	// float absorption;
	// float microThickness;
	// float thickness;
};

#endif