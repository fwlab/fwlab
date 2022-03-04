#ifndef GL_LIGHT_AMBIENT_LIGHT_H
#define GL_LIGHT_AMBIENT_LIGHT_H
#include <utils/Path.h>

namespace gl::light
{
	class AmbientLight
	{
	public:
		AmbientLight(utils::Path iblPath);
		virtual ~AmbientLight();
	};
}

#endif