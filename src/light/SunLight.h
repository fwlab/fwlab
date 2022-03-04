#ifndef FWLAB_LIGHT_SUN_LIGHT_H
#define FWLAB_LIGHT_SUN_LIGHT_H
#include <filament/Color.h>
#include "Light.h"

namespace fwlab::light
{
	class SunLight : public light::Light
	{
	public:
		SunLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		virtual ~SunLight();

		// Light Manager
		float getSunAngularRadius() const;
		float getSunHaloFalloff() const;
		float getSunHaloSize() const;
		void setSunAngularRadius(float angularRadius);
		void setSunHaloFalloff(float haloFalloff);
		void setSunHaloSize(float haloSize);
	};
}

#endif