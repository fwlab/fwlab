#include "Light.h"
#include "../context/context.h"

namespace fwlab::light
{
	Light::Light(filament::LightManager::Type type, filament::sRGBColor color, float intensity)
	{
		auto engine = app->getEngine();

		auto& manager = ::utils::EntityManager::get();
		entity = manager.create();

		filament::LightManager::Builder(type)
			.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(color))
			.intensity(intensity)
			.sunAngularRadius(1.9f)
			.castShadows(true)
			.build(*engine, entity);
	}

	Light::~Light()
	{
		auto engine = app->getEngine();

		if (entity)
		{
			engine->destroy(entity);
		}
	}

	template <typename F>
	void Light::forEachComponent(F func)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		manager.forEachComponent(func);
	}

	const filament::math::float3 Light::getColor() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getColor(manager.getInstance(entity));
	}

	size_t Light::getComponentCount() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getComponentCount();
	}

	const filament::math::float3 Light::getDirection() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getDirection(manager.getInstance(entity));
	}

	const ::utils::Entity* Light::getEntities() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getEntities();
	}

	float Light::getFalloff() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getFalloff(manager.getInstance(entity));
	}

	float Light::getIntensity() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getIntensity(manager.getInstance(entity));
	}

	bool Light::getLightChannel(unsigned int channel) const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getLightChannel(manager.getInstance(entity), channel);
	}

	filament::math::float3 Light::getPosition() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getPosition(manager.getInstance(entity));
	}

	filament::LightManager::ShadowOptions Light::getShadowOptions() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getShadowOptions(manager.getInstance(entity));
	}

	filament::LightManager::Type Light::getType() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.getType(manager.getInstance(entity));
	}

	inline bool Light::isDirectional() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.isDirectional(manager.getInstance(entity));
	}

	inline bool Light::isPointLight() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.isPointLight(manager.getInstance(entity));
	}

	bool Light::isShadowCaster() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.isShadowCaster(manager.getInstance(entity));
	}

	inline bool Light::isSpotLight() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.isSpotLight(manager.getInstance(entity));
	}

	void Light::setColor(const filament::LinearColor color)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setColor(manager.getInstance(entity), color);
	}

	void Light::setDirection(const filament::math::float3 direction)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setDirection(manager.getInstance(entity), direction);
	}

	void Light::setFalloff(float radius)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setFalloff(manager.getInstance(entity), radius);
	}

	void Light::setIntensity(float watts, float efficiency)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setIntensity(manager.getInstance(entity), watts, efficiency);
	}

	void Light::setIntensityCandela(float intensity)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setIntensityCandela(manager.getInstance(entity), intensity);
	}

	void Light::setLightChannel(unsigned int channel, bool enable)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setLightChannel(manager.getInstance(entity), channel, enable);
	}

	void Light::setPosition(const filament::math::float3 position)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setPosition(manager.getInstance(entity), position);
	}

	void Light::setShadowCaster(bool castShadows)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setShadowCaster(manager.getInstance(entity), castShadows);
	}

	void Light::setShadowOptions(filament::LightManager::ShadowOptions const& options)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getLightManager();
		return manager.setShadowOptions(manager.getInstance(entity), options);
	}
}