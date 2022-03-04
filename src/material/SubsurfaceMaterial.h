#ifndef GL_MATERIAL_SUBSURFACE_MATERIAL_H
#define GL_MATERIAL_SUBSURFACE_MATERIAL_H
#include <math/vec3.h>
#include <math/vec4.h>
#include "../texture/Texture.h"
#include "Material.h"

namespace gl::material
{
	class SubsurfaceMaterial : public Material
	{
	public:
		SubsurfaceMaterial();
		virtual ~SubsurfaceMaterial();
		filament::math::float4 getBaseColor() const noexcept;
		void setBaseColor(filament::math::float4 baseColor) noexcept;
		float getMetallic() const noexcept;
		void setMetallic(float metallic) noexcept;
		float getRoughness() const noexcept;
		void setRoughness(float roughness) noexcept;
		float getReflectance() const noexcept;
		void setReflectance(float reflectance) noexcept;
		float getClearCoat() const noexcept;
		void setClearCoat(float clearCoat) noexcept;
		float getClearCoatRoughness() const noexcept;
		void setClearCoatRoughness(float clearCoatRoughness) noexcept;
		float getAnisotropy() const noexcept;
		void setAnisotropy(float anisotropy) noexcept;
		filament::math::float3 getAnisotropyDirection() const noexcept;
		void setAnisotropyDirection(filament::math::float3 anisotropyDirection) noexcept;
		float getAmbientOcclusion() const noexcept;
		void setAmbientOcclusion(float ambientOcclusion) noexcept;
		filament::math::float3 getNormal() const noexcept;						  // not implemented
		void setNormal(filament::math::float3 normal) noexcept;					  // not implemented
		filament::math::float3 getBentNormal() const noexcept;					  // not implemented
		void setBentNormal(filament::math::float3 bentNormal) noexcept;			  // not implemented
		filament::math::float3 getClearCoatNormal() const noexcept;				  // not implemented
		void setClearCoatNormal(filament::math::float3 clearCoatNormal) noexcept; // not implemented
		filament::math::float4 getEmissive() const noexcept;
		void setEmissive(filament::math::float4 emissive) noexcept;
		filament::math::float4 getPostLightingColor() const noexcept;				  // not implemented
		void setPostLightingColor(filament::math::float4 postLightingColor) noexcept; // not implemented
		float getIOR() const noexcept;												  // not implemented
		void setIOR(float ior) noexcept;											  // not implemented
		float getTransmission() const noexcept;										  // not implemented
		void setTransmission(float transmission) noexcept;							  // not implemented
		float getAbsorption() const noexcept;										  // not implemented
		void setAbsorption(float absorption) noexcept;								  // not implemented
		float getMicroThickness() const noexcept;									  // not implemented
		void setMicroThickness(float microThickness) noexcept;						  // not implemented
		float getThickness() const noexcept;
		void setThickness(float thickness) noexcept;
		filament::math::float3 getSubsurfaceColor() const noexcept;
		void setSubsurfaceColor(filament::math::float3 subsurfaceColor) noexcept;
		float getSubsurfacePower() const noexcept;
		void setSubsurfacePower(float subsurfacePower) noexcept;

		gl::texture::Texture *getMap() const noexcept;
		void setMap(gl::texture::Texture *texture) noexcept;

	private:
		filament::math::float4 baseColor = {1, 1, 1, 1};
		float metallic = 1;
		float roughness = 0.5;
		float reflectance = 0.5;
		float clearCoat = 0;
		float clearCoatRoughness = 0.5;
		float anisotropy = 0;
		filament::math::float3 anisotropyDirection = {0, 1, 0};
		float ambientOcclusion = 0;
		filament::math::float3 normal;
		filament::math::float3 bentNormal;
		filament::math::float3 clearCoatNormal;
		filament::math::float4 emissive = {0, 0, 0, 0};
		filament::math::float4 postLightingColor;
		float ior = 0.3;
		float transmission = 0;
		float absorption = 0;
		float microThickness = 0;
		float thickness = 0;
		filament::math::float3 subsurfaceColor = {1, 1, 1};
		float subsurfacePower = 0;

		bool enableMap = false;
		gl::texture::Texture *map = nullptr;
	};
}

#endif