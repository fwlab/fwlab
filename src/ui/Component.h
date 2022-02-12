#ifndef FWLAB_UI_COMPONENT_H
#define FWLAB_UI_COMPONENT_H

namespace ui
{
    class Component
    {
    public:
        Component();
        virtual ~Component();
        virtual void render();
    };
}

#endif