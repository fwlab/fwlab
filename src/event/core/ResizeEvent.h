#ifndef FWLAB_EVENT_CORE_RESIZE_EVENT_H
#define FWLAB_EVENT_CORE_RESIZE_EVENT_H
#include <string>
#include "../BaseEvent.h"

namespace fwlab::event::core
{
	class ResizeEvent final : public event::BaseEvent
	{
	public:
		virtual void start() override;
		virtual void stop() override;

	private:
		void handleResize(void* data);
		const std::string id = "ResizeEvent";
	};
}

#endif