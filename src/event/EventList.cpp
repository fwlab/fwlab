#include "EventList.h"

namespace fwlab::event
{
	// 生命周期事件
	const char* BEFORE_APP_START = "beforeAppStart";
	const char* APP_STARTED = "appStarted";
	const char* BEFORE_RENDER = "beforeRender";
	const char* RENDER = "render";
	const char* ANIMATE = "animate";
	const char* CLOSE = "close";
	const char* BEFORE_APP_STOP = "beforeAppStop";
	const char* APP_STOPPED = "appStopped";

	// SDL事件
	const char* SDL_EVENT = "sdlEvent";

	// 鼠标键盘事件
	const char* KEY_DOWN = "keyDown";
	const char* KEY_UP = "keyUp";
	const char* MOUSE_DOWN = "mouseDown";
	const char* MOUSE_MOVE = "mouseMove";
	const char* MOUSE_UP = "mouseUp";
	const char* WHEEL = "mouseWheel";

	// 场景事件
	const char* SELECT = "select";
	extern const char* SELECT_CHANGED = "selectChanged";

	// 其他事件
	const char* RESIZE = "resize";
	const char* SIZE_CHANGED = "sizeChanged";
	const char* DROP_FILE = "dropFile";
}