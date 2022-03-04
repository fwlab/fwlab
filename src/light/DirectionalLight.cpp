#include "DirectionalLight.h"

namespace fwlab::light
{
	DirectionalLight::DirectionalLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::DIRECTIONAL, color, intensity)
	{
	}

	DirectionalLight::~DirectionalLight()
	{
	}
}