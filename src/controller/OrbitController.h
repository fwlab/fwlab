#ifndef FWLAB_CONTROLLER_ORBIT_CONTROLLER_H
#define FWLAB_CONTROLLER_ORBIT_CONTROLLER_H
#include <string>
#include <camutils/Manipulator.h>
#include "../event/Structure.h"

namespace fwlab::controller
{
	class OrbitController
	{
	public:
		using CameraManipulator = filament::camutils::Manipulator<float>;
		OrbitController();
		virtual ~OrbitController();
		CameraManipulator *getManipulator() const;

	private:
		void handleMouseDown(event::MouseEvent *event) const;
		void handleMouseMove(event::MouseEvent *event) const;
		void handleMouseUp(event::MouseEvent *event) const;
		void handleWheel(event::WheelEvent *event) const;
		void handleKeyDown(event::KeyboardEvent *event) const;
		void handleKeyUp(event::KeyboardEvent *event) const;
		void handleRender() const;
		bool manipulatorKeyFromKeycode(SDL_Scancode scancode, CameraManipulator::Key &key) const;
		const std::string id = "controller";
		CameraManipulator *manipulator = nullptr;
	};
}

#endif