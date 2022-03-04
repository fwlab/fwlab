#include "resources/gl_materials.h"
#include "../utils/Utils.h"
#include "LitMaterial.h"

namespace fwlab::material
{
	LitMaterial::LitMaterial() : Material(GL_MATERIALS_LIT_DATA, GL_MATERIALS_LIT_SIZE)
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

	filament::math::float4 LitMaterial::getBaseColor() const noexcept
	{
		return baseColor;
	}

	void LitMaterial::setBaseColor(filament::math::float4 baseColor) noexcept
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	float LitMaterial::getMetallic() const noexcept
	{
		return metallic;
	}

	void LitMaterial::setMetallic(float metallic) noexcept
	{
		this->metallic = metallic;
		instance->setParameter("metallic", metallic);
	}

	float LitMaterial::getRoughness() const noexcept
	{
		return roughness;
	}

	void LitMaterial::setRoughness(float roughness) noexcept
	{
		this->roughness = roughness;
		instance->setParameter("roughness", roughness);
	}

	float LitMaterial::getReflectance() const noexcept
	{
		return reflectance;
	}

	void LitMaterial::setReflectance(float reflectance) noexcept
	{
		this->reflectance = reflectance;
		ior = utils::Utils::reflectanceToIOR(reflectance);
		instance->setParameter("reflectance", reflectance);
		instance->setParameter("ior", ior);
	}

	filament::math::float3 LitMaterial::getSheenColor() const noexcept
	{
		return sheenColor;
	}

	void LitMaterial::setSheenColor(filament::math::float3 sheenColor) noexcept
	{
		this->sheenColor = sheenColor;
		instance->setParameter("sheenColor", sheenColor);
	}

	float LitMaterial::getSheenRoughness() const noexcept
	{
		return sheenRoughness;
	}

	void LitMaterial::setSheenRoughness(float sheenRoughness) noexcept
	{
		this->sheenRoughness = sheenRoughness;
		instance->setParameter("sheenRoughness", sheenRoughness);
	}

	float LitMaterial::getClearCoat() const noexcept
	{
		return clearCoat;
	}

	void LitMaterial::setClearCoat(float clearCoat) noexcept
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float LitMaterial::getClearCoatRoughness() const noexcept
	{
		return clearCoatRoughness;
	}

	void LitMaterial::setClearCoatRoughness(float clearCoatRoughness) noexcept
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float LitMaterial::getAnisotropy() const noexcept
	{
		return anisotropy;
	}

	void LitMaterial::setAnisotropy(float anisotropy) noexcept
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 LitMaterial::getAnisotropyDirection() const noexcept
	{
		return anisotropyDirection;
	}

	void LitMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection) noexcept
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float LitMaterial::getAmbientOcclusion() const noexcept
	{
		return ambientOcclusion;
	}

	void LitMaterial::setAmbientOcclusion(float ambientOcclusion) noexcept
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 LitMaterial::getNormal() const noexcept
	{
		return normal;
	}

	void LitMaterial::setNormal(filament::math::float3 normal) noexcept
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 LitMaterial::getBentNormal() const noexcept
	{
		return bentNormal;
	}

	void LitMaterial::setBentNormal(filament::math::float3 bentNormal) noexcept
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 LitMaterial::getClearCoatNormal() const noexcept
	{
		return clearCoatNormal;
	}

	void LitMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal) noexcept
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 LitMaterial::getEmissive() const noexcept
	{
		return emissive;
	}

	void LitMaterial::setEmissive(filament::math::float4 emissive) noexcept
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 LitMaterial::getPostLightingColor() const noexcept
	{
		return postLightingColor;
	}

	void LitMaterial::setPostLightingColor(filament::math::float4 postLightingColor) noexcept
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float LitMaterial::getIOR() const noexcept
	{
		return ior;
	}

	void LitMaterial::setIOR(float ior) noexcept
	{
		this->ior = ior;
		reflectance = utils::Utils::iorToReflectance(ior);
		instance->setParameter("ior", ior);
		instance->setParameter("reflectance", reflectance);
	}

	float LitMaterial::getTransmission() const noexcept
	{
		return transmission;
	}

	void LitMaterial::setTransmission(float transmission) noexcept
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float LitMaterial::getAbsorption() const noexcept
	{
		return absorption;
	}

	void LitMaterial::setAbsorption(float absorption) noexcept
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float LitMaterial::getMicroThickness() const noexcept
	{
		return microThickness;
	}

	void LitMaterial::setMicroThickness(float microThickness) noexcept
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float LitMaterial::getThickness() const noexcept
	{
		return thickness;
	}

	void LitMaterial::setThickness(float thickness) noexcept
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	gl::texture::Texture* LitMaterial::getMap() const noexcept
	{
		return map;
	}

	void LitMaterial::setMap(gl::texture::Texture* texture) noexcept
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