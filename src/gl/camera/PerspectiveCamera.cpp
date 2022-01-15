#include "PerspectiveCamera.h"

using namespace gl::camera;

PerspectiveCamera::PerspectiveCamera(double fov, double aspect, double near, double far, filament::Camera::Fov direction)
{
	camera->setProjection(fov, aspect, near, far, direction);
}
