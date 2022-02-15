#include <imgui.h>
#include "HelpMenu.h"

using namespace ui::menubar;

void HelpMenu::render()
{
    if (ImGui::BeginMenu("帮助", true))
    {
        if (ImGui::MenuItem("演示窗口", nullptr, false, true))
        {
            ImGui::ShowDemoWindow(&isOpen);
        }
        if (ImGui::MenuItem("矩阵窗口", nullptr, false, true))
        {
            ImGui::ShowMetricsWindow(&isOpen);
        }
        if (ImGui::MenuItem("样式编辑器", nullptr, false, true))
        {
            ImGui::ShowStyleEditor();
        }
        if (ImGui::MenuItem("关于窗口", nullptr, false, true))
        {
            ImGui::ShowAboutWindow(&isOpen);
        }
        ImGui::EndMenu();
    }
}