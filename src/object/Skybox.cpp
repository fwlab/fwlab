#include "Skybox.h"

Skybox::Skybox(Context* context, filament::math::float4 color, bool showSun)
{
	this->context = context;

	skybox = filament::Skybox::Builder()
		.color(color)
		.showSun(showSun)
		.build(*context->engine);
}

Skybox::Skybox(Context* context, filament::Texture* cubemap, float envIntensity, bool showSun)
{
	this->context = context;

	skybox = filament::Skybox::Builder()
		.environment(cubemap)
		.intensity(envIntensity)
		.showSun(showSun)
		.build(*context->engine);
}

Skybox::~Skybox()
{
	context->engine->destroy(skybox);
}