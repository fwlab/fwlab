#include <resources/resources.h>
#include "UnlitMaterial.h"
#include "../context/context.h"

namespace fwlab::material
{
	UnlitMaterial::UnlitMaterial() : Material(RESOURCES_UNLIT_DATA, RESOURCES_UNLIT_SIZE)
	{
		instance->setParameter("baseColor", baseColor);
		instance->setParameter("emissive", emissive);
		instance->setParameter("postLightingColor", postLightingColor);
		instance->setParameter("enableMap", enableMap);
	}

	UnlitMaterial::~UnlitMaterial()
	{
		if (map)
		{
			delete map;
			enableMap = false;
			map = nullptr;
		}
	}

	filament::math::float4 UnlitMaterial::getBaseColor() const
	{
		return baseColor;
	}

	void UnlitMaterial::setBaseColor(filament::math::float4 baseColor)
	{
		this->baseColor = baseColor;
		setParameter("baseColor", baseColor);
	}

	filament::math::float4 UnlitMaterial::getEmissive() const
	{
		return emissive;
	}

	void UnlitMaterial::setEmissive(filament::math::float4 emissive)
	{
		this->emissive = emissive;
		setParameter("emissive", emissive);
	}

	filament::math::float4 UnlitMaterial::getPostLightingColor() const
	{
		return postLightingColor;
	}

	void UnlitMaterial::setPostLightingColor(filament::math::float4 postLightingColor)
	{
		this->postLightingColor = postLightingColor;
		setParameter("postLightingColor", postLightingColor);
	}

	texture::Texture* UnlitMaterial::getMap() const
	{
		return map;
	}

	void UnlitMaterial::setMap(texture::Texture* texture)
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