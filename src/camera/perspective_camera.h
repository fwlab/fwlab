#ifndef FWLAB_PERSPECTIVE_CAMERA_H
#define FWLAB_PERSPECTIVE_CAMERA_H
#include <filament/Engine.h>
#include <filament/Camera.h>
#include <filament/View.h>
#include <utils/Entity.h>

/// <summary>
/// Õ∏ ”œ‡ª˙
/// </summary>
class PerspectiveCamera {
public:
	explicit PerspectiveCamera(filament::Engine* engine, filament::View* view);
	virtual ~PerspectiveCamera();
	utils::Entity entity;
	filament::Camera* camera;

private:
	filament::Engine* engine;
};

#endif