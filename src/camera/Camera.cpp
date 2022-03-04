#include <utils/EntityManager.h>
#include "Camera.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::camera;

Camera::Camera()
{
	entity = utils::EntityManager::get().create();
	camera = engine->createCamera(entity);
}

Camera::~Camera()
{
	engine->destroy(entity);
	engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}

filament::Camera *Camera::getCamera() const
{
	return camera;
}

void Camera::setCamera(filament::Camera *camera)
{
	this->camera = camera;
}

double Camera::computeEffectiveFocalLength(double focalLength, double focusDistance)
{
	return camera->computeEffectiveFocalLength(focalLength, focusDistance);
}

double Camera::computeEffectiveFov(double fovInDegrees, double focusDistance)
{
	return camera->computeEffectiveFov(fovInDegrees, focusDistance);
}

float Camera::getAperture() const
{
	return camera->getAperture();
}

float Camera::getCullingFar() const
{
	return camera->getCullingFar();
}

filament::math::mat4 Camera::getCullingProjectionMatrix() const
{
	return camera->getCullingProjectionMatrix();
}

float Camera::getFieldOfViewInDegrees(filament::Camera::Fov direction) const
{
	return camera->getFieldOfViewInDegrees(direction);
}

double Camera::getFocalLength() const
{
	return camera->getFocalLength();
}

float Camera::getFocusDistance() const
{
	return camera->getFocusDistance();
}

filament::math::float3 Camera::getForwardVector() const
{
	return camera->getForwardVector();
}

filament::Frustum Camera::getFrustum() const
{
	return camera->getFrustum();
}

filament::math::float3 Camera::getLeftVector() const
{
	return camera->getLeftVector();
}

filament::math::mat4 Camera::getModelMatrix() const
{
	return camera->getModelMatrix();
}

float Camera::getNear() const
{
	return camera->getNear();
}

filament::math::float3 Camera::getPosition() const
{
	return camera->getPosition();
}

filament::math::mat4 Camera::getProjectionMatrix() const
{
	return camera->getProjectionMatrix();
}

filament::math::double4 Camera::getScaling() const
{
	return camera->getScaling();
}

float Camera::getSensitivity() const
{
	return camera->getSensitivity();
}

filament::math::double2 Camera::getShift() const
{
	return camera->getShift();
}

float Camera::getShutterSpeed() const
{
	return camera->getShutterSpeed();
}

filament::math::float3 Camera::getUpVector() const
{
	return camera->getUpVector();
}

filament::math::mat4 Camera::getViewMatrix() const
{
	return camera->getViewMatrix();
}

filament::math::mat4 Camera::inverseProjection(filament::math::mat4 p)
{
	return camera->inverseProjection(p);
}

void Camera::lookAt(filament::math::float3 eye, filament::math::float3 center, filament::math::float3 up)
{
	camera->lookAt(eye, center, up);
}

void Camera::setCustomProjection(filament::math::mat4 projection, double near, double far)
{
	camera->setCustomProjection(projection, near, far);
}

void Camera::setCustomProjection(filament::math::mat4 projection, filament::math::mat4 projectionForCulling, double near, double far)
{
	camera->setCustomProjection(projection, projectionForCulling, near, far);
}

void Camera::setExposure(float aperture, float shutterSpeed, float sensitivity)
{
	camera->setExposure(aperture, shutterSpeed, sensitivity);
}

void Camera::setExposure(float exposure)
{
	camera->setExposure(exposure);
}

void Camera::setFocusDistance(float distance)
{
	camera->setFocusDistance(distance);
}

void Camera::setLensProjection(double focalLengthInMillimeters, double aspect, double near, double far)
{
	camera->setLensProjection(focalLengthInMillimeters, aspect, near, far);
}

void Camera::setModelMatrix(const filament::math::mat4 modelMatrix)
{
	camera->setModelMatrix(modelMatrix);
}

void Camera::setProjection(filament::Camera::Projection projection, double left, double right, double bottom, double top, double near, double far)
{
	camera->setProjection(projection, left, right, bottom, top, near, far);
}

void Camera::setProjection(double fovInDegrees, double aspect, double near, double far, filament::Camera::Fov direction)
{
	camera->setProjection(fovInDegrees, aspect, near, far, direction);
}

void Camera::setScaling(filament::math::double2 scaling)
{
	camera->setScaling(scaling);
}

void Camera::setShift(filament::math::double2 shift)
{
	camera->setShift(shift);
}