#include "PointLight.h"

using gl::light;

void PointLight::PointLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::PointLight, color, intensity)
{

}

virtual PointLight::~PointLight()
{

}