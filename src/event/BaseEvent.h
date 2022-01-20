#ifndef FWLAB_EVENT_BASE_EVENT_H
#define FWLAB_EVENT_BASE_EVENT_H

namespace event
{
	class BaseEvent
	{
	public:
		BaseEvent() = default;
		virtual ~BaseEvent() = default;
		virtual void start() noexcept;
		virtual void stop() noexcept;
	};
}

#endif