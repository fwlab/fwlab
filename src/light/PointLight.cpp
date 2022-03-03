#include "PointLight.h"

using namespace gl::light;

PointLight::PointLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::POINT, color, intensity)
{
}

PointLight::~PointLight()
{
}