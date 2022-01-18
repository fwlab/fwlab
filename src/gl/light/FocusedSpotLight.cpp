#include "FocusedSpotLight.h"

using namespace gl::light;

FocusedSpotLight::FocusedSpotLight(filament::sRGBColor color, float intensity) :
	SpotLight(filament::LightManager::Type::FOCUSED_SPOT, color, intensity)
{

}

FocusedSpotLight::~FocusedSpotLight()
{

}