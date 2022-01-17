#include "DirectionalLight.h"

using gl::light;

void DirectionalLight::DirectionalLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::SUN, color, intensity)
{

}

virtual DirectionalLight::~DirectionalLight()
{

}