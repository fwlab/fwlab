#include <resources/resources.h>
#include "../utils/Utils.h"
#include "LitMaterial.h"

namespace fwlab::material
{
	LitMaterial::LitMaterial() : Material(RESOURCES_LIT_DATA, RESOURCES_LIT_SIZE)
	{
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
		instance->setParameter("metallic", metallic);
		instance->setParameter("roughness", roughness);
		instance->setParameter("reflectance", reflectance);
		instance->setParameter("sheenColor", filament::RgbType::LINEAR, sheenColor);
		instance->setParameter("sheenRoughness", sheenRoughness);
		instance->setParameter("clearCoat", clearCoat);
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
		instance->setParameter("anisotropy", anisotropy);
		instance->setParameter("anisotropyDirection", anisotropyDirection);
		instance->setParameter("ambientOcclusion", ambientOcclusion);
		instance->setParameter("emissive", filament::RgbaType::LINEAR, emissive);
		// instance->setParameter("ior", ior);
		instance->setParameter("enableMap", enableMap);
	}

	LitMaterial::~LitMaterial()
	{
		if (map)
		{
			delete map;
			enableMap = false;
			map = nullptr;
		}
	}

	filament::math::float4 LitMaterial::getBaseColor() const
	{
		return baseColor;
	}

	void LitMaterial::setBaseColor(filament::math::float4 baseColor)
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	float LitMaterial::getMetallic() const
	{
		return metallic;
	}

	void LitMaterial::setMetallic(float metallic)
	{
		this->metallic = metallic;
		instance->setParameter("metallic", metallic);
	}

	float LitMaterial::getRoughness() const
	{
		return roughness;
	}

	void LitMaterial::setRoughness(float roughness)
	{
		this->roughness = roughness;
		instance->setParameter("roughness", roughness);
	}

	float LitMaterial::getReflectance() const
	{
		return reflectance;
	}

	void LitMaterial::setReflectance(float reflectance)
	{
		this->reflectance = reflectance;
		ior = utils::Utils::reflectanceToIOR(reflectance);
		instance->setParameter("reflectance", reflectance);
		instance->setParameter("ior", ior);
	}

	filament::math::float3 LitMaterial::getSheenColor() const
	{
		return sheenColor;
	}

	void LitMaterial::setSheenColor(filament::math::float3 sheenColor)
	{
		this->sheenColor = sheenColor;
		instance->setParameter("sheenColor", sheenColor);
	}

	float LitMaterial::getSheenRoughness() const
	{
		return sheenRoughness;
	}

	void LitMaterial::setSheenRoughness(float sheenRoughness)
	{
		this->sheenRoughness = sheenRoughness;
		instance->setParameter("sheenRoughness", sheenRoughness);
	}

	float LitMaterial::getClearCoat() const
	{
		return clearCoat;
	}

	void LitMaterial::setClearCoat(float clearCoat)
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float LitMaterial::getClearCoatRoughness() const
	{
		return clearCoatRoughness;
	}

	void LitMaterial::setClearCoatRoughness(float clearCoatRoughness)
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float LitMaterial::getAnisotropy() const
	{
		return anisotropy;
	}

	void LitMaterial::setAnisotropy(float anisotropy)
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 LitMaterial::getAnisotropyDirection() const
	{
		return anisotropyDirection;
	}

	void LitMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection)
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float LitMaterial::getAmbientOcclusion() const
	{
		return ambientOcclusion;
	}

	void LitMaterial::setAmbientOcclusion(float ambientOcclusion)
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 LitMaterial::getNormal() const
	{
		return normal;
	}

	void LitMaterial::setNormal(filament::math::float3 normal)
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 LitMaterial::getBentNormal() const
	{
		return bentNormal;
	}

	void LitMaterial::setBentNormal(filament::math::float3 bentNormal)
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 LitMaterial::getClearCoatNormal() const
	{
		return clearCoatNormal;
	}

	void LitMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal)
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 LitMaterial::getEmissive() const
	{
		return emissive;
	}

	void LitMaterial::setEmissive(filament::math::float4 emissive)
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 LitMaterial::getPostLightingColor() const
	{
		return postLightingColor;
	}

	void LitMaterial::setPostLightingColor(filament::math::float4 postLightingColor)
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float LitMaterial::getIOR() const
	{
		return ior;
	}

	void LitMaterial::setIOR(float ior)
	{
		this->ior = ior;
		reflectance = utils::Utils::iorToReflectance(ior);
		instance->setParameter("ior", ior);
		instance->setParameter("reflectance", reflectance);
	}

	float LitMaterial::getTransmission() const
	{
		return transmission;
	}

	void LitMaterial::setTransmission(float transmission)
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float LitMaterial::getAbsorption() const
	{
		return absorption;
	}

	void LitMaterial::setAbsorption(float absorption)
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float LitMaterial::getMicroThickness() const
	{
		return microThickness;
	}

	void LitMaterial::setMicroThickness(float microThickness)
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float LitMaterial::getThickness() const
	{
		return thickness;
	}

	void LitMaterial::setThickness(float thickness)
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	texture::Texture* LitMaterial::getMap() const
	{
		return map;
	}

	void LitMaterial::setMap(texture::Texture* texture)
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