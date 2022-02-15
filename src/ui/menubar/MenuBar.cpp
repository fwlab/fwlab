#include <imgui.h>
#include "MenuBar.h"

using namespace ui::menubar;

void MenuBar::render()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("文件", true))
        {
            ImGui::MenuItem("新建", nullptr, false, true);
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}