#include <imgui.h>
#include "Editor.h"

void Editor::render()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File", true))
        {
            ImGui::MenuItem("New", nullptr, false, true);
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    if (ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_MenuBar))
    {

        ImGui::End();
    }
}
