#include <imgui.h>
#include "EditMenu.h"

using namespace ui::menubar;

void EditMenu::render()
{
    if (ImGui::BeginMenu("编辑", true))
    {
        if (ImGui::MenuItem("撤销", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("重做", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("复制", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("删除", nullptr, false, true))
        {
        }
        ImGui::EndMenu();
    }
}