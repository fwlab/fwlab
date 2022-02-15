#include <imgui.h>
#include "ObjectMenu.h"

using namespace ui::menubar;

void ObjectMenu::render()
{
    if (ImGui::BeginMenu("物体", true))
    {
        if (ImGui::MenuItem("平面", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("正方体", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("球体", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("圆柱体", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("圆锥体", nullptr, false, true))
        {
        }
        ImGui::EndMenu();
    }
}