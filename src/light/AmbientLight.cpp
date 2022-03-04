#include <iostream>
#include "AmbientLight.h"
#include "../context/context.h"

namespace fwlab::light
{
	AmbientLight::AmbientLight(::utils::Path iblPath)
	{
		auto engine = app->getEngine();
		ibl = new IBL(*engine);

		if (!iblPath.isDirectory()) {
			if (!ibl->loadFromEquirect(iblPath)) {
				app->error(std::string("Could not load the specified IBL: ") + iblPath.c_str());
				return;
			}
		}
		else {
			if (!ibl->loadFromDirectory(iblPath)) {
				app->error(std::string("Could not load the specified IBL: ") + iblPath.c_str());
				return;
			}
		}
	}

	AmbientLight::~AmbientLight()
	{
		delete ibl;
	}

	filament::IndirectLight* AmbientLight::getIndirectLight()
	{
		if (ibl)
		{
			return ibl->getIndirectLight();
		}
		return nullptr;
	}

	filament::Skybox* AmbientLight::getSkybox()
	{
		if (ibl)
		{
			return ibl->getSkybox();
		}
		return nullptr;
	}
}