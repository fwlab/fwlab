#include "SpotLight.h"

using gl::light;

void SpotLight::SpotLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::SpotLight, color, intensity)
{

}

virtual SpotLight::~SpotLight()
{

}