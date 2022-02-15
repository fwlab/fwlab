#include <imgui.h>
#include "Editor.h"

void Editor::render()
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

    if (ImGui::Begin("你好", nullptr, ImGuiWindowFlags_MenuBar))
    {
        ImGui::End();
    }
}
