#include "UnlitMaterial.h"
#include <resources/resources.h>

using namespace gl::material;

UnlitMaterial::UnlitMaterial() : Material(RESOURCES_UNLIT_DATA, RESOURCES_UNLIT_SIZE)
{

}

UnlitMaterial::~UnlitMaterial()
{

}

filament::math::float4 UnlitMaterial::getBaseColor() const
{
	return baseColor;
}

void UnlitMaterial::setBaseColor(filament::math::float4 baseColor)
{
	
}

filament::math::float4 UnlitMaterial::getEmissive() const
{
	return emissive;
}

void UnlitMaterial::setEmissive(filament::math::float4 baseColor)
{

}

filament::math::float4 UnlitMaterial::getPostLightingColor() const
{
	return postLightingColor;
}

void UnlitMaterial::setPostLightingColor(filament::math::float4 baseColor)
{

}