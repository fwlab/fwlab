#ifndef FWLAB_LIGHT_SPOT_LIGHT_H
#define FWLAB_LIGHT_SPOT_LIGHT_H
#include <filament/Color.h>
#include "Light.h"

namespace fwlab::light
{
	class SpotLight : public light::Light
	{
	public:
		SpotLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		using light::Light::Light;
		virtual ~SpotLight();

		// Light Manager
		float getSpotLightInnerCone() const;
		float getSpotLightOuterCone() const;
		void setSpotLightCone(float inner, float outer);
	};
}

#endif