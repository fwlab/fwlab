#include <SDL.h>
#include "ResizeEvent.h"
#include "../EventList.h"
#include "../Structure.h"
#include "../../context/context.h"

namespace fwlab::event::core
{
	void ResizeEvent::start()
	{
		app->addEventListener(RESIZE, id, std::bind(&ResizeEvent::handleResize, this, std::placeholders::_1));
	}

	void ResizeEvent::stop()
	{
	}

	void ResizeEvent::handleResize(void* data)
	{
		auto event = reinterpret_cast<event::SizeEvent*>(data);

		auto camera = app->getCamera();

		camera->setProjection(
			camera->getFieldOfViewInDegrees(filament::Camera::Fov::VERTICAL),
			double(event->width) / event->height,
			camera->getNear(),
			camera->getCullingFar());

		auto viewport = app->getViewport();
		viewport->width = event->width;
		viewport->height = event->height;

		auto view = app->getView();
		view->setViewport(*viewport);

		app->dispatchEvent(event::SIZE_CHANGED, event);
	}
}