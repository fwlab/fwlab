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

filament::Camera *Camera::getCamera() const noexcept
{
	return camera;
}

void Camera::setCamera(filament::Camera *camera) noexcept
{
	this->camera = camera;
}

double Camera::computeEffectiveFocalLength(double focalLength, double focusDistance) noexcept
{
	return camera->computeEffectiveFocalLength(focalLength, focusDistance);
}

double Camera::computeEffectiveFov(double fovInDegrees, double focusDistance) noexcept
{
	return camera->computeEffectiveFov(fovInDegrees, focusDistance);
}

float Camera::getAperture() const noexcept
{
	return camera->getAperture();
}

float Camera::getCullingFar() const noexcept
{
	return camera->getCullingFar();
}

filament::math::mat4 Camera::getCullingProjectionMatrix() const noexcept
{
	return camera->getCullingProjectionMatrix();
}

float Camera::getFieldOfViewInDegrees(filament::Camera::Fov direction) const noexcept
{
	return camera->getFieldOfViewInDegrees(direction);
}

double Camera::getFocalLength() const noexcept
{
	return camera->getFocalLength();
}

float Camera::getFocusDistance() const noexcept
{
	return camera->getFocusDistance();
}

filament::math::float3 Camera::getForwardVector() const noexcept
{
	return camera->getForwardVector();
}

filament::Frustum Camera::getFrustum() const noexcept
{
	return camera->getFrustum();
}

filament::math::float3 Camera::getLeftVector() const noexcept
{
	return camera->getLeftVector();
}

filament::math::mat4 Camera::getModelMatrix() const noexcept
{
	return camera->getModelMatrix();
}

float Camera::getNear() const noexcept
{
	return camera->getNear();
}

filament::math::float3 Camera::getPosition() const noexcept
{
	return camera->getPosition();
}

filament::math::mat4 Camera::getProjectionMatrix() const noexcept
{
	return camera->getProjectionMatrix();
}

filament::math::double4 Camera::getScaling() const noexcept
{
	return camera->getScaling();
}

float Camera::getSensitivity() const noexcept
{
	return camera->getSensitivity();
}

filament::math::double2 Camera::getShift() const noexcept
{
	return camera->getShift();
}

float Camera::getShutterSpeed() const noexcept
{
	return camera->getShutterSpeed();
}

filament::math::float3 Camera::getUpVector() const noexcept
{
	return camera->getUpVector();
}

filament::math::mat4 Camera::getViewMatrix() const noexcept
{
	return camera->getViewMatrix();
}

filament::math::mat4 Camera::inverseProjection(filament::math::mat4 p) noexcept
{
	return camera->inverseProjection(p);
}

void Camera::lookAt(filament::math::float3 eye, filament::math::float3 center, filament::math::float3 up) noexcept
{
	camera->lookAt(eye, center, up);
}

void Camera::setCustomProjection(filament::math::mat4 projection, double near, double far) noexcept
{
	camera->setCustomProjection(projection, near, far);
}

void Camera::setCustomProjection(filament::math::mat4 projection, filament::math::mat4 projectionForCulling, double near, double far) noexcept
{
	camera->setCustomProjection(projection, projectionForCulling, near, far);
}

void Camera::setExposure(float aperture, float shutterSpeed, float sensitivity) noexcept
{
	camera->setExposure(aperture, shutterSpeed, sensitivity);
}

void Camera::setExposure(float exposure) noexcept
{
	camera->setExposure(exposure);
}

void Camera::setFocusDistance(float distance) noexcept
{
	camera->setFocusDistance(distance);
}

void Camera::setLensProjection(double focalLengthInMillimeters, double aspect, double near, double far) noexcept
{
	camera->setLensProjection(focalLengthInMillimeters, aspect, near, far);
}

void Camera::setModelMatrix(const filament::math::mat4 modelMatrix) noexcept
{
	camera->setModelMatrix(modelMatrix);
}

void Camera::setProjection(filament::Camera::Projection projection, double left, double right, double bottom, double top, double near, double far) noexcept
{
	camera->setProjection(projection, left, right, bottom, top, near, far);
}

void Camera::setProjection(double fovInDegrees, double aspect, double near, double far, filament::Camera::Fov direction) noexcept
{
	camera->setProjection(fovInDegrees, aspect, near, far, direction);
}

void Camera::setScaling(filament::math::double2 scaling) noexcept
{
	camera->setScaling(scaling);
}

void Camera::setShift(filament::math::double2 shift) noexcept
{
	camera->setShift(shift);
}