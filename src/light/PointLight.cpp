#include "PointLight.h"

namespace fwlab::light
{
	PointLight::PointLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::POINT, color, intensity)
	{
	}

	PointLight::~PointLight()
	{
	}
}