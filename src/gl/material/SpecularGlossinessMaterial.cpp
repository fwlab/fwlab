#include "resources/gl_materials.h"
#include "../utils/Utils.h"
#include "SpecularGlossinessMaterial.h"

using namespace gl::material;

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

filament::math::float4 SpecularGlossinessMaterial::getBaseColor() const noexcept
{
	return baseColor;
}

void SpecularGlossinessMaterial::setBaseColor(filament::math::float4 baseColor) noexcept
{
	this->baseColor = baseColor;
	instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
}

filament::math::float3 SpecularGlossinessMaterial::getSpecularColor() const noexcept
{
	return specularColor;
}

void SpecularGlossinessMaterial::setSpecularColor(filament::math::float3 specularColor) noexcept
{
	this->specularColor = specularColor;
	instance->setParameter("specularColor", specularColor);
}

float SpecularGlossinessMaterial::getGlossiness() const noexcept
{
	return glossiness;
}

void SpecularGlossinessMaterial::setGlossiness(float glossiness) noexcept
{
	this->glossiness = glossiness;
	instance->setParameter("glossiness", glossiness);
}

filament::math::float3 SpecularGlossinessMaterial::getSheenColor() const noexcept
{
	return sheenColor;
}

void SpecularGlossinessMaterial::setSheenColor(filament::math::float3 sheenColor) noexcept
{
	this->sheenColor = sheenColor;
	instance->setParameter("sheenColor", sheenColor);
}

float SpecularGlossinessMaterial::getSheenRoughness() const noexcept
{
	return sheenRoughness;
}

void SpecularGlossinessMaterial::setSheenRoughness(float sheenRoughness) noexcept
{
	this->sheenRoughness = sheenRoughness;
	instance->setParameter("sheenRoughness", sheenRoughness);
}

float SpecularGlossinessMaterial::getClearCoat() const noexcept
{
	return clearCoat;
}

void SpecularGlossinessMaterial::setClearCoat(float clearCoat) noexcept
{
	this->clearCoat = clearCoat;
	instance->setParameter("clearCoat", clearCoat);
}

float SpecularGlossinessMaterial::getClearCoatRoughness() const noexcept
{
	return clearCoatRoughness;
}

void SpecularGlossinessMaterial::setClearCoatRoughness(float clearCoatRoughness) noexcept
{
	this->clearCoatRoughness = clearCoatRoughness;
	instance->setParameter("clearCoatRoughness", clearCoatRoughness);
}

float SpecularGlossinessMaterial::getAnisotropy() const noexcept
{
	return anisotropy;
}

void SpecularGlossinessMaterial::setAnisotropy(float anisotropy) noexcept
{
	this->anisotropy = anisotropy;
	instance->setParameter("anisotropy", anisotropy);
}

filament::math::float3 SpecularGlossinessMaterial::getAnisotropyDirection() const noexcept
{
	return anisotropyDirection;
}

void SpecularGlossinessMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection) noexcept
{
	this->anisotropyDirection = anisotropyDirection;
	instance->setParameter("anisotropyDirection", anisotropyDirection);
}

float SpecularGlossinessMaterial::getAmbientOcclusion() const noexcept
{
	return ambientOcclusion;
}

void SpecularGlossinessMaterial::setAmbientOcclusion(float ambientOcclusion) noexcept
{
	this->ambientOcclusion = ambientOcclusion;
	instance->setParameter("ambientOcclusion", ambientOcclusion);
}

filament::math::float3 SpecularGlossinessMaterial::getNormal() const noexcept
{
	return normal;
}

void SpecularGlossinessMaterial::setNormal(filament::math::float3 normal) noexcept
{
	this->normal = normal;
	instance->setParameter("normal", normal);
}

filament::math::float3 SpecularGlossinessMaterial::getBentNormal() const noexcept
{
	return bentNormal;
}

void SpecularGlossinessMaterial::setBentNormal(filament::math::float3 bentNormal) noexcept
{
	this->bentNormal = bentNormal;
	instance->setParameter("bentNormal", bentNormal);
}

filament::math::float3 SpecularGlossinessMaterial::getClearCoatNormal() const noexcept
{
	return clearCoatNormal;
}

void SpecularGlossinessMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal) noexcept
{
	this->clearCoatNormal = clearCoatNormal;
	instance->setParameter("clearCoatNormal", clearCoatNormal);
}

filament::math::float4 SpecularGlossinessMaterial::getEmissive() const noexcept
{
	return emissive;
}

void SpecularGlossinessMaterial::setEmissive(filament::math::float4 emissive) noexcept
{
	this->emissive = emissive;
	instance->setParameter("emissive", emissive);
}

filament::math::float4 SpecularGlossinessMaterial::getPostLightingColor() const noexcept
{
	return postLightingColor;
}

void SpecularGlossinessMaterial::setPostLightingColor(filament::math::float4 postLightingColor) noexcept
{
	this->postLightingColor = postLightingColor;
	instance->setParameter("postLightingColor", postLightingColor);
}

float SpecularGlossinessMaterial::getTransmission() const noexcept
{
	return transmission;
}

void SpecularGlossinessMaterial::setTransmission(float transmission) noexcept
{
	this->transmission = transmission;
	instance->setParameter("transmission", transmission);
}

float SpecularGlossinessMaterial::getAbsorption() const noexcept
{
	return absorption;
}

void SpecularGlossinessMaterial::setAbsorption(float absorption) noexcept
{
	this->absorption = absorption;
	instance->setParameter("absorption", absorption);
}

float SpecularGlossinessMaterial::getMicroThickness() const noexcept
{
	return microThickness;
}

void SpecularGlossinessMaterial::setMicroThickness(float microThickness) noexcept
{
	this->microThickness = microThickness;
	instance->setParameter("microThickness", microThickness);
}

float SpecularGlossinessMaterial::getThickness() const noexcept
{
	return thickness;
}

void SpecularGlossinessMaterial::setThickness(float thickness) noexcept
{
	this->thickness = thickness;
	instance->setParameter("thickness", thickness);
}

gl::texture::Texture *SpecularGlossinessMaterial::getMap() const noexcept
{
	return map;
}

void SpecularGlossinessMaterial::setMap(gl::texture::Texture *texture) noexcept
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