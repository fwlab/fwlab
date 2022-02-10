#include <SDL.h>
#include "ResizeEvent.h"
#include "../EventList.h"
#include "../Structure.h"
#include "../../context/context.h"

using namespace event::core;

void ResizeEvent::start()
{
    app->addEventListener(RESIZE, id, std::bind(&ResizeEvent::handleResize, this, std::placeholders::_1));
}

void ResizeEvent::stop()
{
}

void ResizeEvent::handleResize(void *data)
{
    auto window = app->getSDLWindow();

    uint32_t width, height;
    SDL_GL_GetDrawableSize(window, (int *)&width, (int *)&height);

    auto camera = app->getCamera();

    camera->setProjection(
        camera->getFieldOfViewInDegrees(filament::Camera::Fov::VERTICAL),
        double(width) / height,
        camera->getNear(),
        camera->getCullingFar());

    auto view = app->getView();
    auto viewport = app->getViewport();

    view->setViewport({0, 0, width, height});

    // auto ui = app->getUIHelper();
    // ui->setViewport({0, 0, width, height});
}