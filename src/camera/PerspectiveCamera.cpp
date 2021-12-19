#include <utils/EntityManager.h>
#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(Context* context, double fov, double aspect, double near, double far, filament::Camera::Fov direction)
{
	this->context = context;

	entity = utils::EntityManager::get().create();

	camera = context->engine->createCamera(entity);
	camera->setProjection(fov, aspect, near, far, direction);
}

PerspectiveCamera::~PerspectiveCamera()
{
	context->engine->destroy(entity);
	context->engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}