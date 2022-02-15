#ifndef UI_MENUBAR_OBJECT_MENU_H
#define UI_MENUBAR_OBJECT_MENU_H
#include "../Component.h"

namespace ui::menubar
{
    class ObjectMenu : public Component
    {
    public:
        void render() override;
    };
}

#endif