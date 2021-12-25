#include <filament/LightManager.h>
#include <utils/EntityManager.h>
#include "Light.h"

using namespace gl::light;

Light::Light(Context* context)
{
	this->context = context;
}

Light::~Light()
{
	if (context && context->engine && entity)
	{
		context->engine->destroy(entity);
	}
}

Light* Light::create()
{
	auto& manager = utils::EntityManager::get();
	entity = manager.create();

	filament::LightManager::Builder(filament::LightManager::Type::SUN)
		.color(filament::Color::toLinear<filament::ColorConversion::ACCURATE>(filament::sRGBColor(0.98f, 0.92f, 0.89f)))
		.intensity(110000)
		.direction({ 0.7, -1, -0.8 })
		.sunAngularRadius(1.9f)
		.castShadows(true)
		.build(*context->engine, entity);
	return this;
}