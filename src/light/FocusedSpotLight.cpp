#include "FocusedSpotLight.h"

namespace fwlab::light
{
	FocusedSpotLight::FocusedSpotLight(filament::sRGBColor color, float intensity) : SpotLight(filament::LightManager::Type::FOCUSED_SPOT, color, intensity)
	{
	}

	FocusedSpotLight::~FocusedSpotLight()
	{
	}
}