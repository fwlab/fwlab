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
		EventDispatcher() = default;
		virtual ~EventDispatcher() = default;
		void start() noexcept override;
		void stop() noexcept override;
		// eventName should be `eventName.id`
		void addEventListener(const std::string& eventName, std::function<void()> listener) noexcept;
		// eventName should be `eventName.id`
		template<typename...args>
		void addEventListener(const std::string& eventName, std::function<void(args...)> listener) noexcept;
		// eventName should be `eventName.id`
		void removeEventListener(const std::string& eventName) noexcept;
		// eventName should be `eventName.id`
		bool hasEventListener(const std::string& eventName) const noexcept;
		// eventName should be `eventName`
		void dispatchEvent(const std::string& eventName) noexcept;

	private:
		bool check(const std::string& eventName);
		struct EventData
		{
			std::string id;
			BaseEvent event;
		};
		std::unordered_map<std::string, EventData> events;
	};
}

#endif