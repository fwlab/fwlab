#include <cmath>
#include "resources/gl_materials.h"
#include "../utils/Utils.h"
#include "ClothMaterial.h"

namespace fwlab::material
{
	ClothMaterial::ClothMaterial() : Material(GL_MATERIALS_LIT_DATA, GL_MATERIALS_LIT_SIZE)
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

	filament::math::float4 ClothMaterial::getBaseColor() const noexcept
	{
		return baseColor;
	}

	void ClothMaterial::setBaseColor(filament::math::float4 baseColor) noexcept
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	float ClothMaterial::getRoughness() const noexcept
	{
		return roughness;
	}

	void ClothMaterial::setRoughness(float roughness) noexcept
	{
		this->roughness = roughness;
		instance->setParameter("roughness", roughness);
	}

	filament::math::float3 ClothMaterial::getSheenColor() const noexcept
	{
		return sheenColor;
	}

	void ClothMaterial::setSheenColor(filament::math::float3 sheenColor) noexcept
	{
		this->sheenColor = sheenColor;
		instance->setParameter("sheenColor", sheenColor);
	}

	filament::math::float3 ClothMaterial::getSubsurfaceColor() const noexcept
	{
		return subsurfaceColor;
	}

	void ClothMaterial::setSubsurfaceColor(filament::math::float3 subsurfaceColor) noexcept
	{
		this->subsurfaceColor = subsurfaceColor;
		// instance->setParameter("subsurfaceColor", subsurfaceColor);
	}

	float ClothMaterial::getClearCoat() const noexcept
	{
		return clearCoat;
	}

	void ClothMaterial::setClearCoat(float clearCoat) noexcept
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float ClothMaterial::getClearCoatRoughness() const noexcept
	{
		return clearCoatRoughness;
	}

	void ClothMaterial::setClearCoatRoughness(float clearCoatRoughness) noexcept
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float ClothMaterial::getAnisotropy() const noexcept
	{
		return anisotropy;
	}

	void ClothMaterial::setAnisotropy(float anisotropy) noexcept
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 ClothMaterial::getAnisotropyDirection() const noexcept
	{
		return anisotropyDirection;
	}

	void ClothMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection) noexcept
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float ClothMaterial::getAmbientOcclusion() const noexcept
	{
		return ambientOcclusion;
	}

	void ClothMaterial::setAmbientOcclusion(float ambientOcclusion) noexcept
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 ClothMaterial::getNormal() const noexcept
	{
		return normal;
	}

	void ClothMaterial::setNormal(filament::math::float3 normal) noexcept
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 ClothMaterial::getBentNormal() const noexcept
	{
		return bentNormal;
	}

	void ClothMaterial::setBentNormal(filament::math::float3 bentNormal) noexcept
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 ClothMaterial::getClearCoatNormal() const noexcept
	{
		return clearCoatNormal;
	}

	void ClothMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal) noexcept
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 ClothMaterial::getEmissive() const noexcept
	{
		return emissive;
	}

	void ClothMaterial::setEmissive(filament::math::float4 emissive) noexcept
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 ClothMaterial::getPostLightingColor() const noexcept
	{
		return postLightingColor;
	}

	void ClothMaterial::setPostLightingColor(filament::math::float4 postLightingColor) noexcept
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float ClothMaterial::getTransmission() const noexcept
	{
		return transmission;
	}

	void ClothMaterial::setTransmission(float transmission) noexcept
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float ClothMaterial::getAbsorption() const noexcept
	{
		return absorption;
	}

	void ClothMaterial::setAbsorption(float absorption) noexcept
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float ClothMaterial::getMicroThickness() const noexcept
	{
		return microThickness;
	}

	void ClothMaterial::setMicroThickness(float microThickness) noexcept
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float ClothMaterial::getThickness() const noexcept
	{
		return thickness;
	}

	void ClothMaterial::setThickness(float thickness) noexcept
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	texture::Texture* ClothMaterial::getMap() const noexcept
	{
		return map;
	}

	void ClothMaterial::setMap(texture::Texture* texture) noexcept
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