#include <filament/Viewport.h>
#include <utils/EntityManager.h>
#include "OrthographicCamera.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::camera;

OrthographicCamera::OrthographicCamera(double left, double right, double top, double bottom, double near, double far)
{
	entity = utils::EntityManager::get().create();

	camera = engine->createCamera(entity);
	camera->setProjection(filament::Camera::Projection::ORTHO, left, right, bottom, top, near, far);

	view->setCamera(camera);
}

OrthographicCamera::~OrthographicCamera()
{
	engine->destroy(entity);
	engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}