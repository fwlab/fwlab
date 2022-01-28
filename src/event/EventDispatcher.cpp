#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <SDL_events.h>
#include "../context/context.h"
#include "EventList.h"
#include "EventStruct.h"
#include "EventDispatcher.h"

using namespace event;

void EventDispatcher::pollEvent() const noexcept
{
	SDL_Event event;

	if (SDL_PollEvent(&event) > 0)
	{
		dispatchEvent(event::SDL_EVENT, &event);
		switch (event.type)
		{
		// 生命周期事件：
		case SDL_QUIT:
			app->dispatchEvent(event::CLOSE);
			app->stop();
			break;
		// 鼠标键盘事件
		case SDL_KEYDOWN:
		{
			KeyboardEvent evt = {.scancode = event.key.keysym.scancode, .event = &event};
			app->dispatchEvent(event::KEY_DOWN, &evt);
			break;
		}
		case SDL_KEYUP:
		{
			KeyboardEvent evt = {.scancode = event.key.keysym.scancode, .event = &event};
			app->dispatchEvent(event::KEY_UP, &evt);
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			MouseEvent evt = {.button = event.button.button, .x = event.button.x, .y = event.button.y, .event = &event};
			app->dispatchEvent(event::MOUSE_DOWN, &evt);
			break;
		}
		case SDL_MOUSEMOTION:
		{
			MouseEvent evt = {.button = event.button.button, .x = event.motion.x, .y = event.motion.y, .event = &event};
			app->dispatchEvent(event::MOUSE_MOVE, &evt);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			MouseEvent evt = {.button = event.button.button, .x = event.button.x, .y = event.button.y, .event = &event};
			app->dispatchEvent(event::MOUSE_UP, &evt);
			break;
		}
		case SDL_MOUSEWHEEL:
		{
			WheelEvent evt = {.deltaX = event.wheel.x, .deltaY = event.wheel.y, .event = &event};
			app->dispatchEvent(event::WHEEL, &evt);
			break;
		}
		// 其他事件
		case SDL_WINDOWEVENT:
		{
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			{
				ResizeEvent evt = {.event = &event};
				app->dispatchEvent(event::RESIZE, &evt);
				break;
			}
			default:
				break;
			}
			break;
		}
		case SDL_DROPFILE:
		{
			DropFileEvent evt = {.file = event.drop.file, .event = &event};
			app->dispatchEvent(event::DROP_FILE);
			SDL_free(event.drop.file);
			break;
		}
		}
	}
}

void EventDispatcher::addEventListener(const std::string eventName, std::string id, std::function<void(void *)> listener) noexcept
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

void EventDispatcher::removeEventListener(const std::string eventName, std::string id) noexcept
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

bool EventDispatcher::hasEventListener(const std::string eventName, std::string id) const noexcept
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

void EventDispatcher::dispatchEvent(const std::string eventName, void *params) const noexcept
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
