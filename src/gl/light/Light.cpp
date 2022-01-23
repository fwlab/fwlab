
#include "Light.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::light;

Light::Light(filament::LightManager::Type type, filament::sRGBColor color, float intensity)
{
	auto &manager = utils::EntityManager::get();
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
	if (entity)
	{
		engine->destroy(entity);
	}
}

template <typename F>
void Light::forEachComponent(F func) noexcept
{
	auto &manager = engine->getLightManager();
	manager.forEachComponent(func);
}

const filament::math::float3 Light::getColor() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getColor(manager.getInstance(entity));
}

size_t Light::getComponentCount() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getComponentCount();
}

const filament::math::float3 Light::getDirection() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getDirection(manager.getInstance(entity));
}

const utils::Entity *Light::getEntities() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getEntities();
}

float Light::getFalloff() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getFalloff(manager.getInstance(entity));
}

float Light::getIntensity() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getIntensity(manager.getInstance(entity));
}

bool Light::getLightChannel(unsigned int channel) const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getLightChannel(manager.getInstance(entity), channel);
}

filament::math::float3 Light::getPosition() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getPosition(manager.getInstance(entity));
}

filament::LightManager::ShadowOptions Light::getShadowOptions() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getShadowOptions(manager.getInstance(entity));
}

filament::LightManager::Type Light::getType() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.getType(manager.getInstance(entity));
}

inline bool Light::isDirectional() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.isDirectional(manager.getInstance(entity));
}

inline bool Light::isPointLight() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.isPointLight(manager.getInstance(entity));
}

bool Light::isShadowCaster() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.isShadowCaster(manager.getInstance(entity));
}

inline bool Light::isSpotLight() const noexcept
{
	auto &manager = engine->getLightManager();
	return manager.isSpotLight(manager.getInstance(entity));
}

void Light::setColor(const filament::LinearColor color) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setColor(manager.getInstance(entity), color);
}

void Light::setDirection(const filament::math::float3 direction) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setDirection(manager.getInstance(entity), direction);
}

void Light::setFalloff(float radius) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setFalloff(manager.getInstance(entity), radius);
}

void Light::setIntensity(float watts, float efficiency) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setIntensity(manager.getInstance(entity), watts, efficiency);
}

void Light::setIntensityCandela(float intensity) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setIntensityCandela(manager.getInstance(entity), intensity);
}

void Light::setLightChannel(unsigned int channel, bool enable) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setLightChannel(manager.getInstance(entity), channel, enable);
}

void Light::setPosition(const filament::math::float3 position) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setPosition(manager.getInstance(entity), position);
}

void Light::setShadowCaster(bool castShadows) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setShadowCaster(manager.getInstance(entity), castShadows);
}

void Light::setShadowOptions(filament::LightManager::ShadowOptions const &options) noexcept
{
	auto &manager = engine->getLightManager();
	return manager.setShadowOptions(manager.getInstance(entity), options);
}
