#include "SunLight.h"
#include "../context/context.h"

namespace fwlab::light
{
	SunLight::SunLight(filament::sRGBColor color, float intensity) : Light(filament::LightManager::Type::SUN, color, intensity)
	{
	}

	SunLight::~SunLight()
	{
	}

	// Light Manager
	float SunLight::getSunAngularRadius() const
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.getSunAngularRadius(manager.getInstance(entity));
	}

	float SunLight::getSunHaloFalloff() const
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.getSunHaloFalloff(manager.getInstance(entity));
	}

	float SunLight::getSunHaloSize() const
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.getSunHaloSize(manager.getInstance(entity));
	}

	void SunLight::setSunAngularRadius(float angularRadius)
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.setSunAngularRadius(manager.getInstance(entity), angularRadius);
	}

	void SunLight::setSunHaloFalloff(float haloFalloff)
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.setSunHaloFalloff(manager.getInstance(entity), haloFalloff);
	}

	void SunLight::setSunHaloSize(float haloSize)
	{
		auto engine = app->getEngine();

		auto &manager = engine->getLightManager();
		return manager.setSunHaloSize(manager.getInstance(entity), haloSize);
	}
}