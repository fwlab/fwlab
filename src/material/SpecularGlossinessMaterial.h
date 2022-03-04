#ifndef FWLAB_MATERIAL_SPECULAR_GLOSSINESS_MATERIAL_H
#define FWLAB_MATERIAL_SPECULAR_GLOSSINESS_MATERIAL_H
#include <math/vec3.h>
#include <math/vec4.h>
#include "../texture/Texture.h"
#include "Material.h"

namespace fwlab::material
{
	class SpecularGlossinessMaterial : public Material
	{
	public:
		SpecularGlossinessMaterial();
		virtual ~SpecularGlossinessMaterial();
		filament::math::float4 getBaseColor() const;
		void setBaseColor(filament::math::float4 baseColor);
		filament::math::float3 getSpecularColor() const;
		void setSpecularColor(filament::math::float3 specularColor);
		float getGlossiness() const;
		void setGlossiness(float glossiness);
		filament::math::float3 getSheenColor() const;
		void setSheenColor(filament::math::float3 sheenColor);
		float getSheenRoughness() const;
		void setSheenRoughness(float sheenRoughness);
		float getClearCoat() const;
		void setClearCoat(float clearCoat);
		float getClearCoatRoughness() const;
		void setClearCoatRoughness(float clearCoatRoughness);
		float getAnisotropy() const;
		void setAnisotropy(float anisotropy);
		filament::math::float3 getAnisotropyDirection() const;
		void setAnisotropyDirection(filament::math::float3 anisotropyDirection);
		float getAmbientOcclusion() const;
		void setAmbientOcclusion(float ambientOcclusion);
		filament::math::float3 getNormal() const;						 // not implemented
		void setNormal(filament::math::float3 normal);					 // not implemented
		filament::math::float3 getBentNormal() const;					 // not implemented
		void setBentNormal(filament::math::float3 bentNormal);			 // not implemented
		filament::math::float3 getClearCoatNormal() const;				 // not implemented
		void setClearCoatNormal(filament::math::float3 clearCoatNormal); // not implemented
		filament::math::float4 getEmissive() const;
		void setEmissive(filament::math::float4 emissive);
		filament::math::float4 getPostLightingColor() const;				 // not implemented
		void setPostLightingColor(filament::math::float4 postLightingColor); // not implemented
		float getTransmission() const;										 // not implemented
		void setTransmission(float transmission);							 // not implemented
		float getAbsorption() const;										 // not implemented
		void setAbsorption(float absorption);								 // not implemented
		float getMicroThickness() const;									 // not implemented
		void setMicroThickness(float microThickness);						 // not implemented
		float getThickness() const;											 // not implemented
		void setThickness(float thickness);									 // not implemented

		texture::Texture *getMap() const;
		void setMap(texture::Texture *texture);

	private:
		filament::math::float4 baseColor = {1, 1, 1, 1};
		filament::math::float3 specularColor = {1, 1, 1};
		float glossiness = 0.5;
		filament::math::float3 sheenColor = {0, 0, 0};
		float sheenRoughness = 1;
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
		float transmission = 0;
		float absorption = 0;
		float microThickness = 0;
		float thickness = 0;

		bool enableMap = false;
		texture::Texture *map = nullptr;
	};
}

#endif