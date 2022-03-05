#include <cmath>
#include <resources/resources.h>
#include "../utils/Utils.h"
#include "ClothMaterial.h"

namespace fwlab::material
{
	ClothMaterial::ClothMaterial() : Material(RESOURCES_CLOTH_DATA, RESOURCES_CLOTH_SIZE)
	{
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
		instance->setParameter("roughness", roughness);
		instance->setParameter("sheenColor", filament::RgbType::LINEAR, sheenColor);
		subsurfaceColor.x = std::sqrt(sheenColor.x);
		subsurfaceColor.y = std::sqrt(sheenColor.y);
		subsurfaceColor.z = std::sqrt(sheenColor.z);
		// instance->setParameter("subsurfaceColor", filament::RgbType::LINEAR, subsurfaceColor);
		instance->setParameter("clearCoat", clearCoat);
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
		instance->setParameter("anisotropy", anisotropy);
		instance->setParameter("anisotropyDirection", anisotropyDirection);
		instance->setParameter("ambientOcclusion", ambientOcclusion);
		instance->setParameter("emissive", filament::RgbaType::LINEAR, emissive);
		instance->setParameter("enableMap", enableMap);
	}

	ClothMaterial::~ClothMaterial()
	{
		if (map)
		{
			delete map;
			enableMap = false;
			map = nullptr;
		}
	}

	filament::math::float4 ClothMaterial::getBaseColor() const
	{
		return baseColor;
	}

	void ClothMaterial::setBaseColor(filament::math::float4 baseColor)
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	float ClothMaterial::getRoughness() const
	{
		return roughness;
	}

	void ClothMaterial::setRoughness(float roughness)
	{
		this->roughness = roughness;
		instance->setParameter("roughness", roughness);
	}

	filament::math::float3 ClothMaterial::getSheenColor() const
	{
		return sheenColor;
	}

	void ClothMaterial::setSheenColor(filament::math::float3 sheenColor)
	{
		this->sheenColor = sheenColor;
		instance->setParameter("sheenColor", sheenColor);
	}

	filament::math::float3 ClothMaterial::getSubsurfaceColor() const
	{
		return subsurfaceColor;
	}

	void ClothMaterial::setSubsurfaceColor(filament::math::float3 subsurfaceColor)
	{
		this->subsurfaceColor = subsurfaceColor;
		// instance->setParameter("subsurfaceColor", subsurfaceColor);
	}

	float ClothMaterial::getClearCoat() const
	{
		return clearCoat;
	}

	void ClothMaterial::setClearCoat(float clearCoat)
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float ClothMaterial::getClearCoatRoughness() const
	{
		return clearCoatRoughness;
	}

	void ClothMaterial::setClearCoatRoughness(float clearCoatRoughness)
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float ClothMaterial::getAnisotropy() const
	{
		return anisotropy;
	}

	void ClothMaterial::setAnisotropy(float anisotropy)
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 ClothMaterial::getAnisotropyDirection() const
	{
		return anisotropyDirection;
	}

	void ClothMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection)
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float ClothMaterial::getAmbientOcclusion() const
	{
		return ambientOcclusion;
	}

	void ClothMaterial::setAmbientOcclusion(float ambientOcclusion)
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 ClothMaterial::getNormal() const
	{
		return normal;
	}

	void ClothMaterial::setNormal(filament::math::float3 normal)
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 ClothMaterial::getBentNormal() const
	{
		return bentNormal;
	}

	void ClothMaterial::setBentNormal(filament::math::float3 bentNormal)
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 ClothMaterial::getClearCoatNormal() const
	{
		return clearCoatNormal;
	}

	void ClothMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal)
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 ClothMaterial::getEmissive() const
	{
		return emissive;
	}

	void ClothMaterial::setEmissive(filament::math::float4 emissive)
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 ClothMaterial::getPostLightingColor() const
	{
		return postLightingColor;
	}

	void ClothMaterial::setPostLightingColor(filament::math::float4 postLightingColor)
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float ClothMaterial::getTransmission() const
	{
		return transmission;
	}

	void ClothMaterial::setTransmission(float transmission)
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float ClothMaterial::getAbsorption() const
	{
		return absorption;
	}

	void ClothMaterial::setAbsorption(float absorption)
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float ClothMaterial::getMicroThickness() const
	{
		return microThickness;
	}

	void ClothMaterial::setMicroThickness(float microThickness)
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float ClothMaterial::getThickness() const
	{
		return thickness;
	}

	void ClothMaterial::setThickness(float thickness)
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	texture::Texture* ClothMaterial::getMap() const
	{
		return map;
	}

	void ClothMaterial::setMap(texture::Texture* texture)
	{
		if (map)
		{
			delete map;
		}
		if (texture)
		{
			enableMap = true;
			map = texture;
			instance->setParameter("enableMap", enableMap);
			instance->setParameter("map", map->getTexture(), *map->getSampler());
		}
		else
		{
			enableMap = false;
			map = nullptr;
		}
	}
}