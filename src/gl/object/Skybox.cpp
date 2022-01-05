#include "../context/context.h"
#include "Skybox.h"

using namespace gl::context;
using namespace gl::object;

Skybox::Skybox(Context* context, filament::math::float4 color, bool showSun)
{
	this->context = context;

	skybox = filament::Skybox::Builder()
		.color(color)
		.showSun(showSun)
		.build(*engine);
}

Skybox::Skybox(Context* context, filament::Texture* cubemap, float envIntensity, bool showSun)
{
	this->context = context;

	skybox = filament::Skybox::Builder()
		.environment(cubemap)
		.intensity(envIntensity)
		.showSun(showSun)
		.build(*engine);
}

Skybox::~Skybox()
{
	context->engine->destroy(skybox);
}