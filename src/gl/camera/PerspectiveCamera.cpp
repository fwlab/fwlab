#include <utils/EntityManager.h>
#include "PerspectiveCamera.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::camera;

PerspectiveCamera::PerspectiveCamera(double fov, double aspect, double near, double far, filament::Camera::Fov direction)
{
	entity = utils::EntityManager::get().create();

	camera = engine->createCamera(entity);
	camera->setProjection(fov, aspect, near, far, direction);
}

PerspectiveCamera::~PerspectiveCamera()
{
	engine->destroy(entity);
	engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}