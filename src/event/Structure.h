#ifndef EVENT_STRUCTURE_H
#define EVENT_STRUCTURE_H
#include <stdint.h>
#include <SDL.h>
#include <SDL_events.h>

namespace event
{
    using KeyboardEvent = struct
    {
        SDL_Scancode scancode;
        SDL_Event *event;
    };

    using MouseEvent = struct
    {
        uint8_t button;
        int32_t x;
        int32_t y;
        SDL_Event *event;
    };

    using WheelEvent = struct
    {
        int32_t deltaX;
        int32_t deltaY;
        SDL_Event *event;
    };

    using ResizeEvent = struct
    {
        int32_t width;
        int32_t height;
        SDL_Event *event;
    };

    using DropFileEvent = struct
    {
        char *file;
        SDL_Event *event;
    };
}

#endif