#ifndef GL_LIGHT_SUN_LIGHT_H
#define GL_LIGHT_SUN_LIGHT_H
#include <filament/Color.h>
#include "Light.h"

namespace gl::light
{
	class SunLight : public gl::light::Light
	{
	public:
		void SunLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000
		);
		virtual ~SunLight();
	};
}

#endif