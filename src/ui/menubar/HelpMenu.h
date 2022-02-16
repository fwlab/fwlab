#ifndef UI_MENUBAR_HELP_MENU_H
#define UI_MENUBAR_HELP_MENU_H
#include "../Component.h"

namespace ui::menubar
{
    class HelpMenu : public Component
    {
    public:
        void render() override;
        bool isDemoWindowShow = false;
        bool isMetricsWindowShow = false;
        bool isAboutWindowShow = false;
        bool isOpen = true;
    };
}

#endif