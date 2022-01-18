#include "DirectionalLight.h"

using namespace gl::light;

DirectionalLight::DirectionalLight(filament::sRGBColor color, float intensity) :
	Light(filament::LightManager::Type::DIRECTIONAL, color, intensity)
{

}

DirectionalLight::~DirectionalLight()
{

}