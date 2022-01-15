#include "OrthographicCamera.h"

using namespace gl::camera;

OrthographicCamera::OrthographicCamera(double left, double right, double top, double bottom, double near, double far)
{
	camera->setProjection(filament::Camera::Projection::ORTHO, left, right, bottom, top, near, far);
}
