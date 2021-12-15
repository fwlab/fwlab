#ifndef FWLAB_ORTHOGRAPHIC_CAMERA_H
#define FWLAB_ORTHOGRAPHIC_CAMERA_H
#include <filament/Camera.h>
#include <utils/Entity.h>
#include "../Context.h"

class OrthographicCamera {
public:
	explicit OrthographicCamera(Context* context, double left = -1, double right = 1, double top = 1, double bottom = -1, double near = 0, double far = 1);
	virtual ~OrthographicCamera();
	utils::Entity entity;
	filament::Camera* camera;

private:
	Context* context;
};

#endif