#ifndef FWLAB_LIGHT_AMBIENT_LIGHT_H
#define FWLAB_LIGHT_AMBIENT_LIGHT_H
#include <string>
#include <filament/IndirectLight.h>
#include <filament/Skybox.h>
#include <utils/Path.h>
#include "../loader/IBL.h"
#include "../utils/Logger.h"

namespace fwlab::light
{
	class AmbientLight
	{
	public:
		AmbientLight(::utils::Path iblPath);
		virtual ~AmbientLight();
		filament::IndirectLight* getIndirectLight();
		filament::Skybox* getSkybox();
		std::string getName();
		void setName(std::string name);

	private:
		IBL* ibl = nullptr;
		std::string name;
	};
}

#endif