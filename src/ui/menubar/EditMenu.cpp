#include <imgui.h>
#include "EditMenu.h"

namespace fwlab::ui::menubar
{
	void EditMenu::render()
	{
		if (ImGui::BeginMenu("编辑", true))
		{
			if (ImGui::MenuItem("撤销", "CTRL+Z", false, true))
			{
			}
			if (ImGui::MenuItem("重做", "CTRL+Y", false, false))
			{
			}
			if (ImGui::MenuItem("复制", "CTRL+D", false, false))
			{
			}
			if (ImGui::MenuItem("删除", "CTRL+Del", false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("清空历史记录", nullptr, false, true))
			{
			}
			ImGui::EndMenu();
		}
	}
}