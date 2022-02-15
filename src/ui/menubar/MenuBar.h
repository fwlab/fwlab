#ifndef UI_MENUBAR_MENU_BAR_H
#define UI_MENUBAR_MENU_BAR_H
#include "../Component.h"
#include "FileMenu.h"
#include "EditMenu.h"
#include "ObjectMenu.h"
#include "HelpMenu.h"

namespace ui::menubar
{
    class MenuBar : public Component
    {
    public:
        MenuBar();
        virtual ~MenuBar();
        void render() override;

    private:
        FileMenu *fileMenu;
        EditMenu *editMenu;
        ObjectMenu *objectMenu;
        HelpMenu *helpMenu;
    };
}

#endif