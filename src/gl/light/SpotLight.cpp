#include "SpotLight.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::light;

SpotLight::SpotLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::SPOT, color, intensity)
{
}

SpotLight::~SpotLight()
{
}

// Light Manager
float SpotLight::getSpotLightInnerCone() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getSpotLightInnerCone(manager.getInstance(entity));
}

float SpotLight::getSpotLightOuterCone() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getSpotLightOuterCone(manager.getInstance(entity));
}

void SpotLight::setSpotLightCone(float inner, float outer) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setSpotLightCone(manager.getInstance(entity), inner, outer);
}