#ifndef GL_LIGHT_LIGHT_H
#define GL_LIGHT_LIGHT_H
#include <utils/Entity.h>

namespace gl::light
{
	class Light {
	public:
		Light();
		virtual ~Light();
		utils::Entity entity;
		Light* create();
	};
}

#endif