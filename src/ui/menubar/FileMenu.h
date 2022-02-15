#ifndef UI_MENUBAR_FILE_MENU_H
#define UI_MENUBAR_FILE_MENU_H
#include "../Component.h"

namespace ui::menubar
{
    class FileMenu : public Component
    {
    public:
        void render() override;
    };
}

#endif