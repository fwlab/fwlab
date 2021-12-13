#include <filament/Viewport.h>
#include <utils/EntityManager.h>
#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(filament::Engine* engine, filament::View* view)
{
	this->engine = engine;

	filament::Viewport viewport = view->getViewport();

	entity = utils::EntityManager::get().create();

	camera = engine->createCamera(entity);
	camera->setProjection(45, viewport.width / viewport.height, 0.1, 1000);
	camera->lookAt({ 10, 10, 10 }, { 0, 0, 0 });

	view->setCamera(camera);
}

PerspectiveCamera::~PerspectiveCamera()
{
	engine->destroy(entity);
	engine->destroyCameraComponent(entity);
	utils::EntityManager::get().destroy(entity);
}