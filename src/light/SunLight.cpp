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
	float SunLight::getSunAngularRadius() const noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getSunAngularRadius(manager.getInstance(entity));
	}

	float SunLight::getSunHaloFalloff() const noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getSunHaloFalloff(manager.getInstance(entity));
	}

	float SunLight::getSunHaloSize() const noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getSunHaloSize(manager.getInstance(entity));
	}

	void SunLight::setSunAngularRadius(float angularRadius) noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setSunAngularRadius(manager.getInstance(entity), angularRadius);
	}

	void SunLight::setSunHaloFalloff(float haloFalloff) noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setSunHaloFalloff(manager.getInstance(entity), haloFalloff);
	}

	void SunLight::setSunHaloSize(float haloSize) noexcept
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setSunHaloSize(manager.getInstance(entity), haloSize);
	}
}