#ifndef GL_LIGHT_FOCUSED_SPOT_LIGHT_H
#define GL_LIGHT_FOCUSED_SPOT_LIGHT_H
#include <filament/Color.h>
#include "SpotLight.h"

namespace gl::light
{
	class FocusedSpotLight : public gl::light::SpotLight
	{
	public:
		FocusedSpotLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		virtual ~FocusedSpotLight();
	};
}

#endif
