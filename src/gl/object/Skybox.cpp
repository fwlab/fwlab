#include "../context/context.h"
#include "Skybox.h"

using namespace gl::context;
using namespace gl::object;

Skybox::Skybox(filament::math::float4 color, bool showSun)
{
	skybox = filament::Skybox::Builder()
				 .color(color)
				 .showSun(showSun)
				 .build(*engine);
}

Skybox::Skybox(filament::Texture *cubemap, float envIntensity, bool showSun)
{
	skybox = filament::Skybox::Builder()
				 .environment(cubemap)
				 .intensity(envIntensity)
				 .showSun(showSun)
				 .build(*engine);
}

Skybox::~Skybox()
{
}