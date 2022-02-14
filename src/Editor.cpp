#include <imgui.h>
#include "Editor.h"

void Editor::render()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu(u8"文件", true))
        {
            ImGui::MenuItem(u8"新建", nullptr, false, true);
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    if (ImGui::Begin(u8"你好", nullptr, ImGuiWindowFlags_MenuBar))
    {
        ImGui::End();
    }
}
