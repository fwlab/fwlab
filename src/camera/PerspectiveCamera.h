#ifndef FWLAB_PERSPECTIVE_CAMERA_H
#define FWLAB_PERSPECTIVE_CAMERA_H
#include <filament/Camera.h>
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// Õ∏ ”œ‡ª˙
/// </summary>
class PerspectiveCamera {
public:
	explicit PerspectiveCamera(Context* context, double fov = 50, double aspect = 1, double near = 0.1, double far = 2000, filament::Camera::Fov direction = filament::Camera::Fov::VERTICAL);
	virtual ~PerspectiveCamera();
	utils::Entity entity;
	filament::Camera* camera;

private:
	Context* context;
};

#endif