#include <imgui.h>
#include "Editor.h"

Editor::Editor()
{
    menubar = new ui::menubar::MenuBar();
    sidebar = new ui::sidebar::SideBar();
}

Editor::~Editor()
{
    delete menubar;
    delete sidebar;
}

void Editor::render()
{
    menubar->render();
    sidebar->render();
}
