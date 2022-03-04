#ifndef FWLAB_EVENT_DISPATCHER_H
#define FWLAB_EVENT_DISPATCHER_H
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include "event/BaseEvent.h"

namespace fwlab
{
	class EventDispatcher final : public event::BaseEvent
	{
	public:
		EventDispatcher();
		virtual ~EventDispatcher();
		void start() override;
		void stop() override;
		void pollEvent() const;
		void addEventListener(const std::string eventName, std::string id, std::function<void(void *)> listener);
		void removeEventListener(const std::string eventName, std::string id);
		bool hasEventListener(const std::string eventName, std::string id) const;
		void dispatchEvent(const std::string eventName, void *params = nullptr) const;

	private:
		struct EventData
		{
			std::string id;
			std::function<void(void *)> listener;
		};
		std::vector<BaseEvent *> events;
		std::unordered_map<std::string, std::vector<EventData>> eventMap;
	};
}

#endif