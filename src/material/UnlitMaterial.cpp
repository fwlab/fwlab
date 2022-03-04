#include <resources/gl_materials.h>
#include "UnlitMaterial.h"
#include "../context/context.h"

namespace fwlab::material
{
	UnlitMaterial::UnlitMaterial() : Material(GL_MATERIALS_UNLIT_DATA, GL_MATERIALS_UNLIT_SIZE)
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

	filament::math::float4 UnlitMaterial::getBaseColor() const noexcept
	{
		return baseColor;
	}

	void UnlitMaterial::setBaseColor(filament::math::float4 baseColor) noexcept
	{
		this->baseColor = baseColor;
		setParameter("baseColor", baseColor);
	}

	filament::math::float4 UnlitMaterial::getEmissive() const noexcept
	{
		return emissive;
	}

	void UnlitMaterial::setEmissive(filament::math::float4 emissive) noexcept
	{
		this->emissive = emissive;
		setParameter("emissive", emissive);
	}

	filament::math::float4 UnlitMaterial::getPostLightingColor() const noexcept
	{
		return postLightingColor;
	}

	void UnlitMaterial::setPostLightingColor(filament::math::float4 postLightingColor) noexcept
	{
		this->postLightingColor = postLightingColor;
		setParameter("postLightingColor", postLightingColor);
	}

	texture::Texture* UnlitMaterial::getMap() const noexcept
	{
		return map;
	}

	void UnlitMaterial::setMap(texture::Texture* texture) noexcept
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