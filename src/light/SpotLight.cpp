#include "SpotLight.h"
#include "../context/context.h"

namespace fwlab::light
{
	SpotLight::SpotLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::SPOT, color, intensity)
	{
	}

	SpotLight::~SpotLight()
	{
	}

	// Light Manager
	float SpotLight::getSpotLightInnerCone() const
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.getSpotLightInnerCone(manager.getInstance(entity));
	}

	float SpotLight::getSpotLightOuterCone() const
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.getSpotLightOuterCone(manager.getInstance(entity));
	}

	void SpotLight::setSpotLightCone(float inner, float outer)
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.setSpotLightCone(manager.getInstance(entity), inner, outer);
	}
}