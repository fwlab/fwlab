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

void EventDispatcher::addEventListener(const std::string& eventName, std::string& id, std::function<void()> listener) noexcept
{
	if (events.find(eventName) == events.end())
	{

	}
	else
	{

	}
}

template<typename...args>
void EventDispatcher::addEventListener(const std::string& eventName, std::string& id, std::function<void(args...)> listener) noexcept
{

}

void EventDispatcher::removeEventListener(const std::string& eventName, std::string& id) noexcept
{

}

bool EventDispatcher::hasEventListener(const std::string& eventName, std::string& id) const noexcept
{

}

void EventDispatcher::dispatchEvent(const std::string& eventName) noexcept
{

}
