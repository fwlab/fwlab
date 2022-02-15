#include <imgui.h>
#include "Editor.h"

Editor::Editor()
{
    menubar = new ui::menubar::MenuBar();
}

Editor::~Editor()
{
    delete menubar;
}

void Editor::render()
{
    menubar->render();
}
