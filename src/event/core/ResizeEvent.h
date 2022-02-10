#ifndef FWLAB_EVENT_CORE_RESIZE_EVENT_H
#define FWLAB_EVENT_CORE_RESIZE_EVENT_H
#include "../BaseEvent.h"

namespace event::core
{
    class ResizeEvent : public event::BaseEvent
    {
    public:
        virtual void start() override;
        virtual void stop() override;
    };
}

#endif