#include <algorithm>
#include <iostream>
#include <SDL.h>
#include "../context/context.h"
#include "EventList.h"
#include "EventDispatcher.h"

using namespace event;

void EventDispatcher::pollEvent() const noexcept
{
	SDL_Event event;

	if (SDL_PollEvent(&event) > 0)
	{
		dispatchEvent(event::SDL_EVENT);
		switch (event.type)
		{
		case SDL_QUIT:
			app->stop();
			break;
		}
	}
}

void EventDispatcher::addEventListener(const std::string &eventName, std::string &id, std::function<void(void *)> listener) noexcept
{
	if (events.find(eventName) == events.end())
	{
		events.insert({eventName, std::vector<EventData>()});
	}
	auto list = events.at(eventName);
	auto pred = [&](EventData &data)
	{ return data.id == id; };
	if (std::find_if(list.begin(), list.end(), pred) == list.end())
	{
		list.push_back({id, listener});
	}
	else
	{
		std::cerr << eventName << "." << id << " has already added" << std::endl;
	}
}

void EventDispatcher::removeEventListener(const std::string &eventName, std::string &id) noexcept
{
	if (events.find(eventName) == events.end())
	{
		std::cerr << eventName << " is not added";
		return;
	}
	auto list = events.at(eventName);
	auto pred = [&](EventData &data)
	{ return data.id == id; };
	list.erase(std::find_if(list.begin(), list.end(), pred));
}

bool EventDispatcher::hasEventListener(const std::string &eventName, std::string &id) const noexcept
{
	if (events.find(eventName) == events.end())
	{
		return false;
	}
	auto list = events.at(eventName);
	auto pred = [&](EventData &data)
	{ return data.id == id; };
	return std::find_if(list.begin(), list.end(), pred) != list.end();
}

void EventDispatcher::dispatchEvent(const std::string &eventName, void *params) const noexcept
{
	if (events.find(eventName) == events.end())
	{
		return;
	}
	auto list = events.at(eventName);
	for (auto &event : list)
	{
		event.listener(params);
	}
}
