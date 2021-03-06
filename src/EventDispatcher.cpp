#include <algorithm>
#include <iostream>
#include <imgui.h>
#include <SDL.h>
#include <SDL_events.h>
#include "context/context.h"
#include "event/EventList.h"
#include "event/Structure.h"
#include "EventDispatcher.h"

// event/core
#include "event/core/ResizeEvent.h"

namespace fwlab
{
	EventDispatcher::EventDispatcher()
	{
		BaseEvent *list[] = {
			new event::core::ResizeEvent()};

		constexpr auto size = sizeof(list) / sizeof(BaseEvent *);

		for (auto i = 0; i < size; i++)
		{
			events.push_back(list[i]);
		}
	}

	EventDispatcher::~EventDispatcher()
	{
		for (auto &event : events)
		{
			delete event;
		}
		events.clear();
	}

	void EventDispatcher::start()
	{
		for (auto &event : events)
		{
			event->start();
		}
	}

	void EventDispatcher::stop()
	{
		for (auto &event : events)
		{
			event->stop();
		}
	}

	void EventDispatcher::pollEvent() const
	{
		SDL_Event event;

		ImGuiIO &io = ImGui::GetIO();

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
				if (!io.WantCaptureKeyboard)
				{
					event::KeyboardEvent evt = {.scancode = event.key.keysym.scancode, .event = &event};
					app->dispatchEvent(event::KEY_DOWN, &evt);
				}
				break;
			}
			case SDL_KEYUP:
			{
				if (!io.WantCaptureKeyboard)
				{
					event::KeyboardEvent evt = {.scancode = event.key.keysym.scancode, .event = &event};
					app->dispatchEvent(event::KEY_UP, &evt);
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				if (!io.WantCaptureMouse)
				{
					event::MouseEvent evt = {.button = event.button.button, .x = event.button.x, .y = event.button.y, .event = &event};
					app->dispatchEvent(event::MOUSE_DOWN, &evt);
				}
				break;
			}
			case SDL_MOUSEMOTION:
			{
				if (!io.WantCaptureMouse)
				{
					event::MouseEvent evt = {.button = event.button.button, .x = event.motion.x, .y = event.motion.y, .event = &event};
					app->dispatchEvent(event::MOUSE_MOVE, &evt);
				}
				break;
			}
			case SDL_MOUSEBUTTONUP:
			{
				if (!io.WantCaptureMouse)
				{
					event::MouseEvent evt = {.button = event.button.button, .x = event.button.x, .y = event.button.y, .event = &event};
					app->dispatchEvent(event::MOUSE_UP, &evt);
				}
				break;
			}
			case SDL_MOUSEWHEEL:
			{
				if (!io.WantCaptureMouse)
				{
					event::WheelEvent evt = {.deltaX = event.wheel.x, .deltaY = event.wheel.y, .event = &event};
					app->dispatchEvent(event::WHEEL, &evt);
				}
				break;
			}
			// 其他事件
			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
				{
					event::SizeEvent evt = {.width = event.window.data1, .height = event.window.data2, .event = &event};
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
				event::DropFileEvent evt = {.file = event.drop.file, .event = &event};
				app->dispatchEvent(event::DROP_FILE);
				SDL_free(event.drop.file);
				break;
			}
			}
		}
	}

	void EventDispatcher::addEventListener(const std::string eventName, std::string id, std::function<void(void *)> listener)
	{
		if (eventMap.find(eventName) == eventMap.end())
		{
			eventMap.insert({eventName, std::vector<EventData>()});
		}
		auto &list = eventMap.at(eventName);
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

	void EventDispatcher::removeEventListener(const std::string eventName, std::string id)
	{
		if (eventMap.find(eventName) == eventMap.end())
		{
			std::cerr << eventName << " is not added";
			return;
		}
		auto list = eventMap.at(eventName);
		auto pred = [&](EventData &data)
		{ return data.id == id; };
		list.erase(std::find_if(list.begin(), list.end(), pred));
	}

	bool EventDispatcher::hasEventListener(const std::string eventName, std::string id) const
	{
		if (eventMap.find(eventName) == eventMap.end())
		{
			return false;
		}
		auto list = eventMap.at(eventName);
		auto pred = [&](EventData &data)
		{ return data.id == id; };
		return std::find_if(list.begin(), list.end(), pred) != list.end();
	}

	void EventDispatcher::dispatchEvent(const std::string eventName, void *params) const
	{
		if (eventMap.find(eventName) == eventMap.end())
		{
			return;
		}
		auto list = eventMap.at(eventName);
		for (auto &event : list)
		{
			event.listener(params);
		}
	}
}