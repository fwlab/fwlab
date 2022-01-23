#ifndef GL_CAMERA_ORTHOGRAPHIC_CAMERA_H
#define GL_CAMERA_ORTHOGRAPHIC_CAMERA_H
#include "Camera.h"

namespace gl::camera
{
	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(double left = -1, double right = 1, double top = 1, double bottom = -1, double near = -1, double far = 1);
	};
}

#endif