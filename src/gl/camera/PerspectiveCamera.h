#ifndef GL_CAMERA_PERSPECTIVE_CAMERA_H
#define GL_CAMERA_PERSPECTIVE_CAMERA_H
#include <filament/Camera.h>
#include <utils/Entity.h>

namespace gl::camera
{
	class PerspectiveCamera {
	public:
		explicit PerspectiveCamera(double fov = 50, double aspect = 1, double near = 0.1, double far = 2000, filament::Camera::Fov direction = filament::Camera::Fov::VERTICAL);
		virtual ~PerspectiveCamera();
		utils::Entity entity;
		filament::Camera* camera;
	};
}

#endif