#include "SunLight.h"

using gl::light;

void SunLight::SunLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::SunLight, color, intensity)
{

}

virtual SunLight::~SunLight()
{

}