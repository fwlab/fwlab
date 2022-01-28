#ifndef EVENT_EVENT_STRUCT_H
#define EVENT_EVENT_STRUCT_H
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
        SDL_Event *event;
    };

    using DropFileEvent = struct
    {
        char *file;
        SDL_Event *event;
    };
}

#endif