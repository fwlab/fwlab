#include <iostream>
#include "AmbientLight.h"
#include "../context/context.h"

namespace gl::light
{
	AmbientLight::AmbientLight(utils::Path iblPath)
	{
		auto engine = app->getEngine();
		ibl = new IBL(*engine);

		if (!iblPath.isDirectory()) {
			if (!ibl->loadFromEquirect(iblPath)) {
				std::cerr << "Could not load the specified IBL: " << iblPath << std::endl;
				return;
			}
		}
		else {
			if (!ibl->loadFromDirectory(iblPath)) {
				std::cerr << "Could not load the specified IBL: " << iblPath << std::endl;
				return;
			}
		}
	}

	AmbientLight::~AmbientLight()
	{
		delete ibl;
	}
}