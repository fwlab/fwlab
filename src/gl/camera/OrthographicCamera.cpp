#include <filament/Viewport.h>
#include <utils/EntityManager.h>
#include "OrthographicCamera.h"

using namespace gl::camera;

OrthographicCamera::OrthographicCamera(Context* context, double left, double right, double top, double bottom, double near, double far)
{
	this->context = context;

	entity = utils::EntityManager::get().create();

	camera = context->engine->createCamera(entity);
	camera->setProjection(filament::Camera::Projection::ORTHO, left, right, bottom, top, near, far);

	context->view->setCamera(camera);
}

OrthographicCamera::~OrthographicCamera()
{
	context->engine->destroy(entity);
	context->engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}