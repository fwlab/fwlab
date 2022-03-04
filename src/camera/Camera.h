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
		filament::Camera *getCamera() const;
		void setCamera(filament::Camera *camera);

		// filament::Camera
		double computeEffectiveFocalLength(double focalLength, double focusDistance);
		double computeEffectiveFov(double fovInDegrees, double focusDistance);
		float getAperture() const;
		float getCullingFar() const;
		filament::math::mat4 getCullingProjectionMatrix() const;
		float getFieldOfViewInDegrees(filament::Camera::Fov direction) const;
		double getFocalLength() const;
		float getFocusDistance() const;
		filament::math::float3 getForwardVector() const;
		filament::Frustum getFrustum() const;
		filament::math::float3 getLeftVector() const;
		filament::math::mat4 getModelMatrix() const;
		float getNear() const;
		filament::math::float3 getPosition() const;
		filament::math::mat4 getProjectionMatrix() const;
		filament::math::double4 getScaling() const;
		float getSensitivity() const;
		filament::math::double2 getShift() const;
		float getShutterSpeed() const;
		filament::math::float3 getUpVector() const;
		filament::math::mat4 getViewMatrix() const;
		filament::math::mat4 inverseProjection(filament::math::mat4 p);
		void lookAt(filament::math::float3 eye, filament::math::float3 center, filament::math::float3 up = {0, 1, 0});
		void setCustomProjection(filament::math::mat4 projection, double near, double far);
		void setCustomProjection(filament::math::mat4 projection, filament::math::mat4 projectionForCulling, double near, double far);
		void setExposure(float aperture, float shutterSpeed, float sensitivity);
		void setExposure(float exposure);
		void setFocusDistance(float distance);
		void setLensProjection(double focalLengthInMillimeters, double aspect, double near, double far);
		void setModelMatrix(const filament::math::mat4 modelMatrix);
		void setProjection(filament::Camera::Projection projection, double left, double right, double bottom, double top, double near, double far);
		void setProjection(double fovInDegrees, double aspect, double near, double far, filament::Camera::Fov direction);
		void setScaling(filament::math::double2 scaling);
		void setShift(filament::math::double2 shift);

	protected:
		filament::Camera *camera = nullptr;
	};
}

#endif