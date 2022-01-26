#include <algorithm>
#include <SDL.h>
#include "../context/context.h"
#include "EventDispatcher.h"

using namespace event;

void EventDispatcher::pollEvent() const noexcept
{
	SDL_Event event;

	if (SDL_PollEvent(&event) > 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			app->stop();
			break;
		}
	}
}

void EventDispatcher::addEventListener(const std::string &eventName, std::string &id, std::function<void()> listener) noexcept
{
	if (events.find(eventName) == events.end())
	{
	}
	else
	{
	}
}

template <typename... args>
void EventDispatcher::addEventListener(const std::string &eventName, std::string &id, std::function<void(args...)> listener) noexcept
{
}

void EventDispatcher::removeEventListener(const std::string &eventName, std::string &id) noexcept
{
}

bool EventDispatcher::hasEventListener(const std::string &eventName, std::string &id) const noexcept
{
	return true;
}

void EventDispatcher::dispatchEvent(const std::string &eventName) noexcept
{
}
