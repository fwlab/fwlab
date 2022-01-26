#ifndef FWLAB_EVENT_EVENT_DISPATCHER_H
#define FWLAB_EVENT_EVENT_DISPATCHER_H
#include <functional>
#include <string>
#include <unordered_map>
#include "BaseEvent.h"

namespace event
{
	class EventDispatcher : public BaseEvent
	{
	public:
		void pollEvent() const noexcept;
		void addEventListener(const std::string &eventName, std::string &id, std::function<void()> listener) noexcept;
		template <typename... args>
		void addEventListener(const std::string &eventName, std::string &id, std::function<void(args...)> listener) noexcept;
		void removeEventListener(const std::string &eventName, std::string &id) noexcept;
		bool hasEventListener(const std::string &eventName, std::string &id) const noexcept;
		void dispatchEvent(const std::string &eventName) noexcept;

	private:
		struct EventData
		{
			std::string id;
			BaseEvent event;
		};
		std::unordered_map<std::string, EventData> events;
	};
}

#endif