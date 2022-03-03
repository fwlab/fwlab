#ifndef GL_LIGHT_SUN_LIGHT_H
#define GL_LIGHT_SUN_LIGHT_H
#include <filament/Color.h>
#include "Light.h"

namespace gl::light
{
	class SunLight : public gl::light::Light
	{
	public:
		SunLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		virtual ~SunLight();

		// Light Manager
		float getSunAngularRadius() const noexcept;
		float getSunHaloFalloff() const noexcept;
		float getSunHaloSize() const noexcept;
		void setSunAngularRadius(float angularRadius) noexcept;
		void setSunHaloFalloff(float haloFalloff) noexcept;
		void setSunHaloSize(float haloSize) noexcept;
	};
}

#endif