#ifndef FWLAB_EVENT_STRUCTURE_H
#define FWLAB_EVENT_STRUCTURE_H
#include <stdint.h>
#include <SDL.h>
#include <SDL_events.h>

namespace fwlab::event
{
	// 生命周期事件
	using Time = struct
	{
		// 从开始渲染到当前的时间（单位：秒）
		double time;
		// 两次渲染间隔的时间（单位：秒）
		double deltaTime;
	};

	// 键盘鼠标事件
	using KeyboardEvent = struct
	{
		SDL_Scancode scancode;
		SDL_Event* event;
	};

	using MouseEvent = struct
	{
		uint8_t button;
		int32_t x;
		int32_t y;
		SDL_Event* event;
	};

	using WheelEvent = struct
	{
		int32_t deltaX;
		int32_t deltaY;
		SDL_Event* event;
	};

	// 其他事件
	using SizeEvent = struct
	{
		int32_t width;
		int32_t height;
		SDL_Event* event;
	};

	using DropFileEvent = struct
	{
		char* file;
		SDL_Event* event;
	};
}

#endif