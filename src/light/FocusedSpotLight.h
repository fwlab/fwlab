#ifndef FWLAB_LIGHT_FOCUSED_SPOT_LIGHT_H
#define FWLAB_LIGHT_FOCUSED_SPOT_LIGHT_H
#include <filament/Color.h>
#include "SpotLight.h"

namespace fwlab::light
{
	class FocusedSpotLight : public light::SpotLight
	{
	public:
		FocusedSpotLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		virtual ~FocusedSpotLight();
	};
}

#endif
