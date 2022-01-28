#ifndef CONTROLLER_ORBIT_CONTROLLER_H
#define CONTROLLER_ORBIT_CONTROLLER_H
#include <string>
#include <camutils/Manipulator.h>
#include "../event/EventStruct.h"

namespace controller
{
    class OrbitController
    {
    public:
        using CameraManipulator = filament::camutils::Manipulator<float>;
        OrbitController();
        virtual ~OrbitController();
        CameraManipulator *getManipulator() const noexcept;

    private:
        void handleMouseDown(event::MouseEvent *event) const noexcept;
        void handleMouseMove(event::MouseEvent *event) const noexcept;
        void handleMouseUp(event::MouseEvent *event) const noexcept;
        void handleWheel(event::WheelEvent *event) const noexcept;
        void handleKeyDown(event::KeyboardEvent *event) const noexcept;
        void handleKeyUp(event::KeyboardEvent *event) const noexcept;
        void handleRender() const noexcept;
        bool manipulatorKeyFromKeycode(SDL_Scancode scancode, CameraManipulator::Key &key) const noexcept;
        const std::string id = "controller";
        CameraManipulator *manipulator = nullptr;
    };
}

#endif