#ifndef FWLAB_EVENT_LIST_H
#define FWLAB_EVENT_LIST_H
#include <string>

namespace event
{
	// 生命周期事件
	extern const char *BEFORE_APP_START;
	extern const char *APP_STARTED;
	extern const char *BEFORE_RENDER;
	extern const char *RENDER;
	extern const char *ANIMATE;
	extern const char *CLOSE;
	extern const char *BEFORE_APP_STOP;
	extern const char *APP_STOPPED;

	// SDL事件
	extern const char *SDL_EVENT;

	// 鼠标键盘事件
	extern const char *KEY_DOWN;
	extern const char *KEY_UP;
	extern const char *MOUSE_DOWN;
	extern const char *MOUSE_MOVE;
	extern const char *MOUSE_UP;
	extern const char *WHEEL;

	// 其他事件
	extern const char *RESIZE;
	extern const char *DROP_FILE;
}

#endif