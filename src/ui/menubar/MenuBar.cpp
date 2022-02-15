#include <imgui.h>
#include "MenuBar.h"

using namespace ui::menubar;

MenuBar::MenuBar()
{
    fileMenu = new FileMenu();
    editMenu = new EditMenu();
}

MenuBar::~MenuBar()
{
    delete fileMenu;
    delete editMenu;
}

void MenuBar::render()
{
    if (ImGui::BeginMainMenuBar())
    {
        fileMenu->render();
        editMenu->render();

        ImGui::EndMainMenuBar();
    }
}