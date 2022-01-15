#ifndef GL_CAMERA_PERSPECTIVE_CAMERA_H
#define GL_CAMERA_PERSPECTIVE_CAMERA_H
#include "Camera.h"

namespace gl::camera
{
	class PerspectiveCamera : public Camera {
	public:
		PerspectiveCamera(double fov = 50, double aspect = 1, double near = 0.1, double far = 2000, filament::Camera::Fov direction = filament::Camera::Fov::VERTICAL);
	};
}

#endif