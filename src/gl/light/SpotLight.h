#ifndef GL_LIGHT_SPOT_LIGHT_H
#define GL_LIGHT_SPOT_LIGHT_H
#include <filament/Color.h>
#include "Light.h"

namespace gl::light
{
	class SpotLight : public gl::light::Light
	{
	public:
		SpotLight(
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		using gl::light::Light::Light;
		virtual ~SpotLight();

		// Light Manager
		float getSpotLightInnerCone() const noexcept;
		float getSpotLightOuterCone() const noexcept;
		void setSpotLightCone(float inner, float outer) noexcept;
	};
}

#endif