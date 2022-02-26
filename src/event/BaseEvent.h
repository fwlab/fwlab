#ifndef FWLAB_EVENT_BASE_EVENT_H
#define FWLAB_EVENT_BASE_EVENT_H

namespace fwlab::event
{
	class BaseEvent
	{
	public:
		BaseEvent() = default;
		virtual ~BaseEvent() = default;
		virtual void start();
		virtual void stop();
	};
}

#endif