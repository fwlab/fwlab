#ifndef UI_MENUBAR_H
#define UI_MENUBAR_H
#include "../Component.h"

namespace ui::menubar
{
    class MenuBar : public Component
    {
    public:
        void render() override;
    };
}

#endif