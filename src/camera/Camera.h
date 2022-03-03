#ifndef GL_CAMERA_H
#define GL_CAMERA_H
#include <filament/Camera.h>
#include <filament/Frustum.h>
#include <math/mat4.h>
#include <math/vec2.h>
#include <math/vec3.h>
#include <math/vec4.h>
#include "../core/Object3D.h"

namespace gl::camera
{
	class Camera : gl::core::Object3D
	{
	public:
		Camera();
		virtual ~Camera();
		filament::Camera *getCamera() const noexcept;
		void setCamera(filament::Camera *camera) noexcept;

		// filament::Camera
		double computeEffectiveFocalLength(double focalLength, double focusDistance) noexcept;
		double computeEffectiveFov(double fovInDegrees, double focusDistance) noexcept;
		float getAperture() const noexcept;
		float getCullingFar() const noexcept;
		filament::math::mat4 getCullingProjectionMatrix() const noexcept;
		float getFieldOfViewInDegrees(filament::Camera::Fov direction) const noexcept;
		double getFocalLength() const noexcept;
		float getFocusDistance() const noexcept;
		filament::math::float3 getForwardVector() const noexcept;
		filament::Frustum getFrustum() const noexcept;
		filament::math::float3 getLeftVector() const noexcept;
		filament::math::mat4 getModelMatrix() const noexcept;
		float getNear() const noexcept;
		filament::math::float3 getPosition() const noexcept;
		filament::math::mat4 getProjectionMatrix() const noexcept;
		filament::math::double4 getScaling() const noexcept;
		float getSensitivity() const noexcept;
		filament::math::double2 getShift() const noexcept;
		float getShutterSpeed() const noexcept;
		filament::math::float3 getUpVector() const noexcept;
		filament::math::mat4 getViewMatrix() const noexcept;
		filament::math::mat4 inverseProjection(filament::math::mat4 p) noexcept;
		void lookAt(filament::math::float3 eye, filament::math::float3 center, filament::math::float3 up = {0, 1, 0}) noexcept;
		void setCustomProjection(filament::math::mat4 projection, double near, double far) noexcept;
		void setCustomProjection(filament::math::mat4 projection, filament::math::mat4 projectionForCulling, double near, double far) noexcept;
		void setExposure(float aperture, float shutterSpeed, float sensitivity) noexcept;
		void setExposure(float exposure) noexcept;
		void setFocusDistance(float distance) noexcept;
		void setLensProjection(double focalLengthInMillimeters, double aspect, double near, double far) noexcept;
		void setModelMatrix(const filament::math::mat4 modelMatrix) noexcept;
		void setProjection(filament::Camera::Projection projection, double left, double right, double bottom, double top, double near, double far) noexcept;
		void setProjection(double fovInDegrees, double aspect, double near, double far, filament::Camera::Fov direction) noexcept;
		void setScaling(filament::math::double2 scaling) noexcept;
		void setShift(filament::math::double2 shift) noexcept;

	protected:
		filament::Camera *camera = nullptr;
	};
}

#endif