#include <algorithm>
#include <utils/Log.h>
#include "EventDispatcher.h"

using namespace event;

void EventDispatcher::start() noexcept
{

}

void EventDispatcher::stop() noexcept
{

}

void EventDispatcher::addEventListener(const std::string& eventName, std::function<void()> listener) noexcept
{
	if (!check(eventName))
	{
		return;
	}
	if (eventMap.find(eventName) != eventMap.end())
	{
		return;
	}
}

template<typename...args>
void EventDispatcher::addEventListener(const std::string& eventName, std::function<void(args...)> listener) noexcept
{

}

void EventDispatcher::removeEventListener(const std::string& eventName) noexcept
{

}

bool EventDispatcher::hasEventListener(const std::string& eventName) const noexcept
{

}

void EventDispatcher::dispatchEvent(const std::string& eventName) noexcept
{

}

bool EventDispatcher::check(const std::string& eventName)
{
	if (std::find(eventName.begin(), eventName.end(), ".") == eventName.end())
	{
		utils::slog.w << "eventName should be `eventName.id`";
		return false;
	}

	return true;
}