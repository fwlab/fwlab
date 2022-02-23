#include <stdint.h>
#include <SDL_syswm.h>
#include "SDLUtils.h"

using namespace utils;

void* SDLUtils::getNativeWindow(SDL_Window* sdlWindow)
{
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	SDL_GetWindowWMInfo(sdlWindow, &wmi);

	if (wmi.subsystem == SDL_VIDEO_DRIVER_WINDOWS)
	{
#if defined(SDL_VIDEO_DRIVER_WINDOWS)
		return wmi.info.win.window;
#endif
	}
	if (wmi.subsystem == SDL_SYSWM_X11)
	{
#if defined(FILAMENT_SUPPORTS_X11)
		Window win = (Window)wmi.info.x11.window;
		return (void*)win;
#endif
	}
	else if (wmi.subsystem == SDL_SYSWM_WAYLAND)
	{
#if defined(FILAMENT_SUPPORTS_WAYLAND)
		return wmi.info.wl.display;
#endif
	}
	return nullptr;
}