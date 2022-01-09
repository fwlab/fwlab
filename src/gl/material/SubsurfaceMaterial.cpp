#include "resources/gl_materials.h"
#include "../utils/Utils.h"
#include "SubsurfaceMaterial.h"

using namespace gl::material;

SubsurfaceMaterial::SubsurfaceMaterial() : Material(GL_MATERIALS_SUBSURFACE_DATA, GL_MATERIALS_SUBSURFACE_SIZE)
{
	instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	instance->setParameter("metallic", metallic);
	instance->setParameter("roughness", roughness);
	instance->setParameter("reflectance", reflectance);
	instance->setParameter("clearCoat", clearCoat);
	instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	instance->setParameter("anisotropy", anisotropy);
	instance->setParameter("anisotropyDirection", anisotropyDirection);
	instance->setParameter("ambientOcclusion", ambientOcclusion);
	instance->setParameter("emissive", filament::RgbaType::LINEAR, emissive);
	// instance->setParameter("ior", ior);
	instance->setParameter("enableMap", enableMap);
}

SubsurfaceMaterial::~SubsurfaceMaterial()
{
	if (map)
	{
		delete map;
		enableMap = false;
		map = nullptr;
	}
}

filament::math::float4 SubsurfaceMaterial::getBaseColor() const noexcept
{
	return baseColor;
}

void SubsurfaceMaterial::setBaseColor(filament::math::float4 baseColor) noexcept
{
	this->baseColor = baseColor;
	instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
}

float SubsurfaceMaterial::getMetallic() const noexcept
{
	return metallic;
}

void SubsurfaceMaterial::setMetallic(float metallic) noexcept
{
	this->metallic = metallic;
	instance->setParameter("metallic", metallic);
}

float SubsurfaceMaterial::getRoughness() const noexcept
{
	return roughness;
}

void SubsurfaceMaterial::setRoughness(float roughness) noexcept
{
	this->roughness = roughness;
	instance->setParameter("roughness", roughness);
}

float SubsurfaceMaterial::getReflectance() const noexcept
{
	return reflectance;
}

void SubsurfaceMaterial::setReflectance(float reflectance) noexcept
{
	this->reflectance = reflectance;
	ior = gl::utils::Utils::reflectanceToIOR(reflectance);
	instance->setParameter("reflectance", reflectance);
	instance->setParameter("ior", ior);
}

float SubsurfaceMaterial::getClearCoat() const noexcept
{
	return clearCoat;
}

void SubsurfaceMaterial::setClearCoat(float clearCoat) noexcept
{
	this->clearCoat = clearCoat;
	instance->setParameter("clearCoat", clearCoat);
}

float SubsurfaceMaterial::getClearCoatRoughness() const noexcept
{
	return clearCoatRoughness;
}

void SubsurfaceMaterial::setClearCoatRoughness(float clearCoatRoughness) noexcept
{
	this->clearCoatRoughness = clearCoatRoughness;
	instance->setParameter("clearCoatRoughness", clearCoatRoughness);
}

float SubsurfaceMaterial::getAnisotropy() const noexcept
{
	return anisotropy;
}

void SubsurfaceMaterial::setAnisotropy(float anisotropy) noexcept
{
	this->anisotropy = anisotropy;
	instance->setParameter("anisotropy", anisotropy);
}

filament::math::float3 SubsurfaceMaterial::getAnisotropyDirection() const noexcept
{
	return anisotropyDirection;
}

void SubsurfaceMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection) noexcept
{
	this->anisotropyDirection = anisotropyDirection;
	instance->setParameter("anisotropyDirection", anisotropyDirection);
}

float SubsurfaceMaterial::getAmbientOcclusion() const noexcept
{
	return ambientOcclusion;
}

void SubsurfaceMaterial::setAmbientOcclusion(float ambientOcclusion) noexcept
{
	this->ambientOcclusion = ambientOcclusion;
	instance->setParameter("ambientOcclusion", ambientOcclusion);
}

filament::math::float3 SubsurfaceMaterial::getNormal() const noexcept
{
	return normal;
}

void SubsurfaceMaterial::setNormal(filament::math::float3 normal) noexcept
{
	this->normal = normal;
	instance->setParameter("normal", normal);
}

filament::math::float3 SubsurfaceMaterial::getBentNormal() const noexcept
{
	return bentNormal;
}

void SubsurfaceMaterial::setBentNormal(filament::math::float3 bentNormal) noexcept
{
	this->bentNormal = bentNormal;
	instance->setParameter("bentNormal", bentNormal);
}

filament::math::float3 SubsurfaceMaterial::getClearCoatNormal() const noexcept
{
	return clearCoatNormal;
}

void SubsurfaceMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal) noexcept
{
	this->clearCoatNormal = clearCoatNormal;
	instance->setParameter("clearCoatNormal", clearCoatNormal);
}

filament::math::float4 SubsurfaceMaterial::getEmissive() const noexcept
{
	return emissive;
}

void SubsurfaceMaterial::setEmissive(filament::math::float4 emissive) noexcept
{
	this->emissive = emissive;
	instance->setParameter("emissive", emissive);
}

filament::math::float4 SubsurfaceMaterial::getPostLightingColor() const noexcept
{
	return postLightingColor;
}

void SubsurfaceMaterial::setPostLightingColor(filament::math::float4 postLightingColor) noexcept
{
	this->postLightingColor = postLightingColor;
	instance->setParameter("postLightingColor", postLightingColor);
}

float SubsurfaceMaterial::getIOR() const noexcept
{
	return ior;
}

void SubsurfaceMaterial::setIOR(float ior) noexcept
{
	this->ior = ior;
	reflectance = gl::utils::Utils::iorToReflectance(ior);
	instance->setParameter("ior", ior);
	instance->setParameter("reflectance", reflectance);
}

float SubsurfaceMaterial::getTransmission() const noexcept
{
	return transmission;
}

void SubsurfaceMaterial::setTransmission(float transmission) noexcept
{
	this->transmission = transmission;
	instance->setParameter("transmission", transmission);
}

float SubsurfaceMaterial::getAbsorption() const noexcept
{
	return absorption;
}

void SubsurfaceMaterial::setAbsorption(float absorption) noexcept
{
	this->absorption = absorption;
	instance->setParameter("absorption", absorption);
}

float SubsurfaceMaterial::getMicroThickness() const noexcept
{
	return microThickness;
}

void SubsurfaceMaterial::setMicroThickness(float microThickness) noexcept
{
	this->microThickness = microThickness;
	instance->setParameter("microThickness", microThickness);
}

float SubsurfaceMaterial::getThickness() const noexcept
{
	return thickness;
}

void SubsurfaceMaterial::setThickness(float thickness) noexcept
{
	this->thickness = thickness;
	instance->setParameter("thickness", thickness);
}

filament::math::float3 SubsurfaceMaterial::getSubsurfaceColor() const noexcept
{
	return subsurfaceColor;
}

void SubsurfaceMaterial::setSubsurfaceColor(filament::math::float3 subsurfaceColor) noexcept
{
	this->subsurfaceColor = subsurfaceColor;
	instance->setParameter("subsurfaceColor", subsurfaceColor);
}

float SubsurfaceMaterial::getSubsurfacePower()  const noexcept
{
	return subsurfacePower;
}

void SubsurfaceMaterial::setSubsurfacePower(float subsurfacePower) noexcept
{
	this->subsurfacePower = subsurfacePower;
	instance->setParameter("subsurfacePower", subsurfacePower);
}

gl::texture::Texture* SubsurfaceMaterial::getMap() const noexcept
{
	return map;
}

void SubsurfaceMaterial::setMap(gl::texture::Texture* texture) noexcept
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