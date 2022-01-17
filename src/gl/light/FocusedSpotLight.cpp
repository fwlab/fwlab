#include "FocusedSpotLight.h"

using gl::light;

void FocusedSpotLight::FocusedSpotLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::FocusedSpotLight, color, intensity)
{

}

virtual FocusedSpotLight::~FocusedSpotLight()
{

}