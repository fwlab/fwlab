#include "UnlitMaterial.h"
#include <resources/gl_materials.h>

using namespace gl::material;

UnlitMaterial::UnlitMaterial() : Material(GL_MATERIALS_UNLIT_DATA, GL_MATERIALS_UNLIT_SIZE)
{
	instance->setParameter("baseColor", baseColor);
	instance->setParameter("emissive", emissive);
	instance->setParameter("postLightingColor", postLightingColor);
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