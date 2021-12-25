#ifndef GL_OBJECT_SKYBOX_H
#define GL_OBJECT_SKYBOX_H
#include <filament/Skybox.h>
#include "../Context.h"

namespace gl::object
{
	class Skybox {
	public:
		explicit Skybox(Context* context, filament::math::float4 color = { 0.1, 0.125, 0.25, 1.0 }, bool showSun = false);
		explicit Skybox(Context* context, filament::Texture* cubemap, float envIntensity = 30000, bool showSun = false);
		virtual ~Skybox();
		filament::Skybox* skybox;

	private:
		Context* context;
	};
}

#endif