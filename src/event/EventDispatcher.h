#ifndef EVENT_EVENT_DISPATCHER_H
#define EVENT_EVENT_DISPATCHER_H
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include "BaseEvent.h"

namespace event
{
	class EventDispatcher : public BaseEvent
	{
	public:
		void pollEvent() const noexcept;
		void addEventListener(const std::string &eventName, std::string &id, std::function<void(void *)> listener) noexcept;
		void removeEventListener(const std::string &eventName, std::string &id) noexcept;
		bool hasEventListener(const std::string &eventName, std::string &id) const noexcept;
		void dispatchEvent(const std::string &eventName, void *params = nullptr) noexcept;

	private:
		struct EventData
		{
			std::string id;
			std::function<void(void *)> listener;
		};
		std::unordered_map<std::string, std::vector<EventData>> events;
	};
}

#endif