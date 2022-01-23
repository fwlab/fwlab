#ifndef FWLAB_UTILS_SDL_UTILS_H
#define FWLAB_UTILS_SDL_UTILS_H
#include <SDL.h>

namespace utils
{
    class SDLUtils
    {
    public:
        static void *getNativeWindow(SDL_Window *sdlWindow);
    };
}

#endif