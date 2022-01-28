#include <math/vec3.h>
#include "../context/context.h"
#include "../event/EventList.h"
#include "OrbitController.h"

using namespace controller;

OrbitController::OrbitController()
{
    manipulator = CameraManipulator::Builder()
                      .targetPosition(0, 0, -4)
                      .flightMoveDamping(15.0)
                      .build(filament::camutils::Mode::ORBIT);
    auto viewport = app->getViewport();
    manipulator->setViewport(viewport->width, viewport->height);

    app->addEventListener(event::MOUSE_DOWN, id, [&](void *event)
                          { handleMouseDown(reinterpret_cast<event::MouseEvent *>(event)); });
    app->addEventListener(event::MOUSE_MOVE, id, [&](void *event)
                          { handleMouseMove(reinterpret_cast<event::MouseEvent *>(event)); });
    app->addEventListener(event::MOUSE_UP, id, [&](void *event)
                          { handleMouseUp(reinterpret_cast<event::MouseEvent *>(event)); });
    app->addEventListener(event::WHEEL, id, [&](void *event)
                          { handleWheel(reinterpret_cast<event::WheelEvent *>(event)); });
    app->addEventListener(event::KEY_DOWN, id, [&](void *event)
                          { handleKeyDown(reinterpret_cast<event::KeyboardEvent *>(event)); });
    app->addEventListener(event::KEY_UP, id, [&](void *event)
                          { handleKeyUp(reinterpret_cast<event::KeyboardEvent *>(event)); });
    app->addEventListener(event::RENDER, id, [&](void *event)
                          { handleRender(); });
}

OrbitController::~OrbitController()
{
    delete manipulator;
}

filament::camutils::Manipulator<float> *OrbitController::getManipulator() const noexcept
{
    return manipulator;
}

void OrbitController::handleMouseDown(event::MouseEvent *event) const noexcept
{
    manipulator->grabBegin(event->x, event->y, event->button == 3);
}

void OrbitController::handleMouseMove(event::MouseEvent *event) const noexcept
{
    manipulator->grabUpdate(event->x, event->y);
}

void OrbitController::handleMouseUp(event::MouseEvent *event) const noexcept
{
    manipulator->grabEnd();
}

void OrbitController::handleWheel(event::WheelEvent *event) const noexcept
{
    manipulator->scroll(0, 0, event->deltaY);
}

void OrbitController::handleKeyDown(event::KeyboardEvent *event) const noexcept
{
    CameraManipulator::Key key;
    if (manipulatorKeyFromKeycode(event->scancode, key))
    {
        manipulator->keyDown(key);
    }
}

void OrbitController::handleKeyUp(event::KeyboardEvent *event) const noexcept
{
    CameraManipulator::Key key;
    if (manipulatorKeyFromKeycode(event->scancode, key))
    {
        manipulator->keyUp(key);
    }
}

void OrbitController::handleRender() const noexcept
{
    filament::math::float3 eye, center, up;
    manipulator->getLookAt(&eye, &center, &up);
    app->getCamera()->lookAt(eye, center, up);
}

bool OrbitController::manipulatorKeyFromKeycode(SDL_Scancode scancode, CameraManipulator::Key &key) const noexcept
{
    switch (scancode)
    {
    case SDL_SCANCODE_W:
        key = CameraManipulator::Key::FORWARD;
        return true;
    case SDL_SCANCODE_A:
        key = CameraManipulator::Key::LEFT;
        return true;
    case SDL_SCANCODE_S:
        key = CameraManipulator::Key::BACKWARD;
        return true;
    case SDL_SCANCODE_D:
        key = CameraManipulator::Key::RIGHT;
        return true;
    case SDL_SCANCODE_E:
        key = CameraManipulator::Key::UP;
        return true;
    case SDL_SCANCODE_Q:
        key = CameraManipulator::Key::DOWN;
        return true;
    default:
        return false;
    }
}