#ifndef OBJECT_SKY_SKY_BOX_H
#define OBJECT_SKY_SKY_BOX_H
#include <filament/Skybox.h>
#include <math/vec4.h>

namespace object::sky
{
	class Skybox
	{
	public:
		Skybox(filament::math::float4 color = {0.1, 0.125, 0.25, 1.0}, bool showSun = false);
		Skybox(filament::Texture *cubemap, float envIntensity = 30000, bool showSun = false);
		virtual ~Skybox();
		filament::Skybox *getSkybox() const;

	private:
		filament::Skybox *skybox;
	};
}

#endif