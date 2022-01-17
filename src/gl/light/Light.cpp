
#include "Light.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::light;

Light::Light(filament::LightManager::Type type, filament::sRGBColor color, float intensity, filament::math::float3 direction) {
	auto& manager = utils::EntityManager::get();
	entity = manager.create();

	filament::LightManager::Builder(type)
		.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(color))
		.intensity(intensity)
		.direction(direction)
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
