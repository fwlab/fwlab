#include "../../context/context.h"
#include "SkyBox.h"

namespace fwlab::object::sky
{
	Skybox::Skybox(filament::math::float4 color, bool showSun)
	{
		skybox = filament::Skybox::Builder()
			.color(color)
			.showSun(showSun)
			.build(*app->getEngine());
	}

	Skybox::Skybox(filament::Texture* cubemap, float envIntensity, bool showSun)
	{
		skybox = filament::Skybox::Builder()
			.environment(cubemap)
			.intensity(envIntensity)
			.showSun(showSun)
			.build(*app->getEngine());
	}

	Skybox::~Skybox()
	{
		app->getEngine()->destroy(skybox);
	}

	filament::Skybox* Skybox::getSkybox() const
	{
		return skybox;
	}
}