#ifndef FWLAB_OBJECT_SKYBOX_H
#define FWLAB_OBJECT_SKYBOX_H
#include <filament/Skybox.h>

namespace fwlab::object
{
	class Skybox
	{
	public:
		explicit Skybox(filament::math::float4 color = { 0.1, 0.125, 0.25, 1.0 }, bool showSun = false);
		explicit Skybox(filament::Texture* cubemap, float envIntensity = 30000, bool showSun = false);
		virtual ~Skybox();
		filament::Skybox* skybox;
	};
}

#endif