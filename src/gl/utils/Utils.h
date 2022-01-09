#ifndef GL_UTILS_H
#define GL_UTILS_H

namespace gl::utils
{
	class Utils
	{
	public:
		static float reflectanceToIOR(float reflectance);
		static float iorToReflectance(float ior);
	};
}

#endif