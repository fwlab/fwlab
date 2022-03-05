#include <resources/resources.h>
#include "../utils/Utils.h"
#include "SubsurfaceMaterial.h"

namespace fwlab::material
{
	SubsurfaceMaterial::SubsurfaceMaterial() : Material(RESOURCES_SUBSURFACE_DATA, RESOURCES_SUBSURFACE_SIZE)
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

	filament::math::float4 SubsurfaceMaterial::getBaseColor() const
	{
		return baseColor;
	}

	void SubsurfaceMaterial::setBaseColor(filament::math::float4 baseColor)
	{
		this->baseColor = baseColor;
		instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	}

	float SubsurfaceMaterial::getMetallic() const
	{
		return metallic;
	}

	void SubsurfaceMaterial::setMetallic(float metallic)
	{
		this->metallic = metallic;
		instance->setParameter("metallic", metallic);
	}

	float SubsurfaceMaterial::getRoughness() const
	{
		return roughness;
	}

	void SubsurfaceMaterial::setRoughness(float roughness)
	{
		this->roughness = roughness;
		instance->setParameter("roughness", roughness);
	}

	float SubsurfaceMaterial::getReflectance() const
	{
		return reflectance;
	}

	void SubsurfaceMaterial::setReflectance(float reflectance)
	{
		this->reflectance = reflectance;
		ior = utils::Utils::reflectanceToIOR(reflectance);
		instance->setParameter("reflectance", reflectance);
		instance->setParameter("ior", ior);
	}

	float SubsurfaceMaterial::getClearCoat() const
	{
		return clearCoat;
	}

	void SubsurfaceMaterial::setClearCoat(float clearCoat)
	{
		this->clearCoat = clearCoat;
		instance->setParameter("clearCoat", clearCoat);
	}

	float SubsurfaceMaterial::getClearCoatRoughness() const
	{
		return clearCoatRoughness;
	}

	void SubsurfaceMaterial::setClearCoatRoughness(float clearCoatRoughness)
	{
		this->clearCoatRoughness = clearCoatRoughness;
		instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	}

	float SubsurfaceMaterial::getAnisotropy() const
	{
		return anisotropy;
	}

	void SubsurfaceMaterial::setAnisotropy(float anisotropy)
	{
		this->anisotropy = anisotropy;
		instance->setParameter("anisotropy", anisotropy);
	}

	filament::math::float3 SubsurfaceMaterial::getAnisotropyDirection() const
	{
		return anisotropyDirection;
	}

	void SubsurfaceMaterial::setAnisotropyDirection(filament::math::float3 anisotropyDirection)
	{
		this->anisotropyDirection = anisotropyDirection;
		instance->setParameter("anisotropyDirection", anisotropyDirection);
	}

	float SubsurfaceMaterial::getAmbientOcclusion() const
	{
		return ambientOcclusion;
	}

	void SubsurfaceMaterial::setAmbientOcclusion(float ambientOcclusion)
	{
		this->ambientOcclusion = ambientOcclusion;
		instance->setParameter("ambientOcclusion", ambientOcclusion);
	}

	filament::math::float3 SubsurfaceMaterial::getNormal() const
	{
		return normal;
	}

	void SubsurfaceMaterial::setNormal(filament::math::float3 normal)
	{
		this->normal = normal;
		instance->setParameter("normal", normal);
	}

	filament::math::float3 SubsurfaceMaterial::getBentNormal() const
	{
		return bentNormal;
	}

	void SubsurfaceMaterial::setBentNormal(filament::math::float3 bentNormal)
	{
		this->bentNormal = bentNormal;
		instance->setParameter("bentNormal", bentNormal);
	}

	filament::math::float3 SubsurfaceMaterial::getClearCoatNormal() const
	{
		return clearCoatNormal;
	}

	void SubsurfaceMaterial::setClearCoatNormal(filament::math::float3 clearCoatNormal)
	{
		this->clearCoatNormal = clearCoatNormal;
		instance->setParameter("clearCoatNormal", clearCoatNormal);
	}

	filament::math::float4 SubsurfaceMaterial::getEmissive() const
	{
		return emissive;
	}

	void SubsurfaceMaterial::setEmissive(filament::math::float4 emissive)
	{
		this->emissive = emissive;
		instance->setParameter("emissive", emissive);
	}

	filament::math::float4 SubsurfaceMaterial::getPostLightingColor() const
	{
		return postLightingColor;
	}

	void SubsurfaceMaterial::setPostLightingColor(filament::math::float4 postLightingColor)
	{
		this->postLightingColor = postLightingColor;
		instance->setParameter("postLightingColor", postLightingColor);
	}

	float SubsurfaceMaterial::getIOR() const
	{
		return ior;
	}

	void SubsurfaceMaterial::setIOR(float ior)
	{
		this->ior = ior;
		reflectance = utils::Utils::iorToReflectance(ior);
		instance->setParameter("ior", ior);
		instance->setParameter("reflectance", reflectance);
	}

	float SubsurfaceMaterial::getTransmission() const
	{
		return transmission;
	}

	void SubsurfaceMaterial::setTransmission(float transmission)
	{
		this->transmission = transmission;
		instance->setParameter("transmission", transmission);
	}

	float SubsurfaceMaterial::getAbsorption() const
	{
		return absorption;
	}

	void SubsurfaceMaterial::setAbsorption(float absorption)
	{
		this->absorption = absorption;
		instance->setParameter("absorption", absorption);
	}

	float SubsurfaceMaterial::getMicroThickness() const
	{
		return microThickness;
	}

	void SubsurfaceMaterial::setMicroThickness(float microThickness)
	{
		this->microThickness = microThickness;
		instance->setParameter("microThickness", microThickness);
	}

	float SubsurfaceMaterial::getThickness() const
	{
		return thickness;
	}

	void SubsurfaceMaterial::setThickness(float thickness)
	{
		this->thickness = thickness;
		instance->setParameter("thickness", thickness);
	}

	filament::math::float3 SubsurfaceMaterial::getSubsurfaceColor() const
	{
		return subsurfaceColor;
	}

	void SubsurfaceMaterial::setSubsurfaceColor(filament::math::float3 subsurfaceColor)
	{
		this->subsurfaceColor = subsurfaceColor;
		instance->setParameter("subsurfaceColor", subsurfaceColor);
	}

	float SubsurfaceMaterial::getSubsurfacePower() const
	{
		return subsurfacePower;
	}

	void SubsurfaceMaterial::setSubsurfacePower(float subsurfacePower)
	{
		this->subsurfacePower = subsurfacePower;
		instance->setParameter("subsurfacePower", subsurfacePower);
	}

	texture::Texture* SubsurfaceMaterial::getMap() const
	{
		return map;
	}

	void SubsurfaceMaterial::setMap(texture::Texture* texture)
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