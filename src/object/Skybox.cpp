#include "Skybox.h"
#include "../context/context.h"

namespace fwlab::object
{
	Skybox::Skybox(filament::math::float4 color, bool showSun)
	{
		auto engine = app->getEngine();

		skybox = filament::Skybox::Builder()
			.color(color)
			.showSun(showSun)
			.build(*engine);
	}

	Skybox::Skybox(filament::Texture* cubemap, float envIntensity, bool showSun)
	{
		auto engine = app->getEngine();

		skybox = filament::Skybox::Builder()
			.environment(cubemap)
			.intensity(envIntensity)
			.showSun(showSun)
			.build(*engine);
	}

	Skybox::~Skybox()
	{
	}
}