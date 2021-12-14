#include "Skybox.h"

Skybox::Skybox(filament::Engine* engine, filament::math::float4 color, bool showSun)
{
	this->engine = engine;

	skybox = filament::Skybox::Builder()
		.color(color)
		.showSun(showSun)
		.build(*engine);
}

Skybox::Skybox(filament::Engine* engine, filament::Texture* cubemap, float envIntensity, bool showSun)
{
	this->engine = engine;

	skybox = filament::Skybox::Builder()
		.environment(cubemap)
		.intensity(envIntensity)
		.showSun(showSun)
		.build(*engine);
}

Skybox::~Skybox()
{
	engine->destroy(skybox);
}