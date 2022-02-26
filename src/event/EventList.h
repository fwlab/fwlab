#ifndef FWLAB_EVENT_EVENT_LIST_H
#define FWLAB_EVENT_EVENT_LIST_H
#include <string>

namespace fwlab::event
{
	// 生命周期事件
	extern const char* BEFORE_APP_START; // 参数：无
	extern const char* APP_STARTED;		 // 参数：无
	extern const char* BEFORE_RENDER;	 // 参数：Time
	extern const char* RENDER;			 // 参数：Time
	extern const char* ANIMATE;			 // 参数：Time
	extern const char* CLOSE;			 // 参数：无
	extern const char* BEFORE_APP_STOP;	 // 参数：无
	extern const char* APP_STOPPED;		 // 参数：无

	// SDL事件
	extern const char* SDL_EVENT; // 参数：SDL_Event

	// 键盘鼠标事件
	extern const char* KEY_DOWN;   // 参数：KeyboardEvent
	extern const char* KEY_UP;	   // 参数：KeyboardEvent
	extern const char* MOUSE_DOWN; // 参数：MouseEvent
	extern const char* MOUSE_MOVE; // 参数：MouseEvent
	extern const char* MOUSE_UP;   // 参数：MouseEvent
	extern const char* WHEEL;	   // 参数：WheelEvent

	// 其他事件
	extern const char* RESIZE;		 // 参数：SizeEvent
	extern const char* SIZE_CHANGED; // 参数：SizeEvent
	extern const char* DROP_FILE;	 // 参数：DropFileEvent
}

#endif