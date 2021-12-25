#ifndef GL_LIGHT_LIGHT_H
#define GL_LIGHT_LIGHT_H
#include <utils/Entity.h>
#include "../Context.h"

namespace gl::light
{
	class Light {
	public:
		Light(Context* context);
		virtual ~Light();
		utils::Entity entity;
		Light* create();

	private:
		Context* context;
	};
}

#endif