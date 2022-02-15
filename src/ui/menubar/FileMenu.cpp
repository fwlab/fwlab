#include <imgui.h>
#include "FileMenu.h"

using namespace ui::menubar;

void FileMenu::render()
{
    if (ImGui::BeginMenu("文件", true))
    {
        if (ImGui::MenuItem("新建", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("打开", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("关闭", nullptr, false, true))
        {
        }
        if (ImGui::MenuItem("退出", nullptr, false, true))
        {
        }
        ImGui::EndMenu();
    }
}