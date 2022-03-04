#include "resources/gl_materials.h"
#include "../utils/Utils.h"
#include "SpecularGlossinessMaterial.h"

namespace fwlab::material
{
	SpecularGlossinessMaterial::SpecularGlossinessMaterial() : Material(GL_MATERIALS_SPECULAR_GLOSSINESS_DATA, GL_MATERIALS_SPECULAR_GLOSSINESS_SIZE)
	{
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
		instance->setParameter("specularColor", specularColor);
		instance->setParameter("glossiness", glossiness);
		instance->setParameter("sheenColor", filament::RgbType::LINEAR, sheenColor);
		instance->setParameter("sheenRoughness", sheenRoughness);
		instance->setParameter("clearCoat", clearCoat);
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
		instance->setParameter("anisotropy", anisotropy);
		instance->setParameter("anisotropyDirection", anisotropyDirection);
		instance->setParameter("ambientOcclusion", ambientOcclusion);
		instance->setParameter("emissive", filament::RgbaType::LINEAR, emissive);
		instance->setParameter("enableMap", enableMap);
	}

	SpecularGlossinessMaterial::~SpecularGlossinessMaterial()
	{
		if (map)
		{
			delete map;
			enableMap = false;
			map = nullptr;
		}
	}

	filament::math::float4 SpecularGlossinessMaterial::getBaseColor() const
	{
		return baseColor;
	}

	void SpecularGlossinessMaterial::setBaseColor(filament::math::float4 baseColor)
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	filament::math::float3 SpecularGlossinessMaterial::getSpecularColor() const
	{
		return specularColor;
	}

	void SpecularGlossinessMaterial::setSpecularColor(filament::math::float3 specularColor)
	{
		this->specularColor = specularColor;
		instance->setParameter("specularColor", specularColor);
	}

	float SpecularGlossinessMaterial::getGlossiness() const
	{
		return glossiness;
	}

	void SpecularGlossinessMaterial::setGlossiness(float glossiness)
	{
		this->glossiness = glossiness;
		instance->setParameter("glossiness", glossiness);
	}

	filament::math::float3 SpecularGlossinessMaterial::getSheenColor() const
	{
		return sheenColor;
	}

	void SpecularGlossinessMaterial::setSheenColor(filament::math::float3 sheenColor)
	{
		this->sheenColor = sheenColor;
		instance->setParameter("sheenColor", sheenColor);
	}

	float SpecularGlossinessMaterial::getSheenRoughness() const
	{
		return sheenRoughness;
	}

	void SpecularGlossinessMaterial::setSheenRoughness(float sheenRoughness)
	{
		this->sheenRoughness = sheenRoughness;
		instance->setParameter("sheenRoughness", sheenRoughness);
	}

	float SpecularGlossinessMaterial::getClearCoat() const
	{
		return clearCoat;
	}

	void SpecularGlossinessMaterial::setClearCoat(float clearCoat)
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float SpecularGlossinessMaterial::getClearCoatRoughness() const
	{
		return clearCoatRoughness;
	}

	void SpecularGlossinessMaterial::setClearCoatRoughness(float clearCoatRoughness)
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float SpecularGlossinessMaterial::getAnisotropy() const
	{
		return anisotropy;
	}

	void SpecularGlossinessMaterial::setAnisotropy(float anisotropy)
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 SpecularGlossinessMaterial::getAnisotropyDirection() const
	{
		return anisotropyDirection;
	}

	void SpecularGlossinessMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection)
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float SpecularGlossinessMaterial::getAmbientOcclusion() const
	{
		return ambientOcclusion;
	}

	void SpecularGlossinessMaterial::setAmbientOcclusion(float ambientOcclusion)
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 SpecularGlossinessMaterial::getNormal() const
	{
		return normal;
	}

	void SpecularGlossinessMaterial::setNormal(filament::math::float3 normal)
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 SpecularGlossinessMaterial::getBentNormal() const
	{
		return bentNormal;
	}

	void SpecularGlossinessMaterial::setBentNormal(filament::math::float3 bentNormal)
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 SpecularGlossinessMaterial::getClearCoatNormal() const
	{
		return clearCoatNormal;
	}

	void SpecularGlossinessMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal)
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 SpecularGlossinessMaterial::getEmissive() const
	{
		return emissive;
	}

	void SpecularGlossinessMaterial::setEmissive(filament::math::float4 emissive)
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 SpecularGlossinessMaterial::getPostLightingColor() const
	{
		return postLightingColor;
	}

	void SpecularGlossinessMaterial::setPostLightingColor(filament::math::float4 postLightingColor)
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float SpecularGlossinessMaterial::getTransmission() const
	{
		return transmission;
	}

	void SpecularGlossinessMaterial::setTransmission(float transmission)
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float SpecularGlossinessMaterial::getAbsorption() const
	{
		return absorption;
	}

	void SpecularGlossinessMaterial::setAbsorption(float absorption)
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float SpecularGlossinessMaterial::getMicroThickness() const
	{
		return microThickness;
	}

	void SpecularGlossinessMaterial::setMicroThickness(float microThickness)
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float SpecularGlossinessMaterial::getThickness() const
	{
		return thickness;
	}

	void SpecularGlossinessMaterial::setThickness(float thickness)
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	texture::Texture *SpecularGlossinessMaterial::getMap() const
	{
		return map;
	}

	void SpecularGlossinessMaterial::setMap(texture::Texture *texture)
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