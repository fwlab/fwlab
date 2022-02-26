#include <imgui.h>
#include "FileMenu.h"

namespace fwlab::ui::menubar
{
	void FileMenu::render()
	{
		if (ImGui::BeginMenu("文件", true))
		{
			if (ImGui::MenuItem("新建", "Ctrl+N", false, true))
			{
			}
			if (ImGui::MenuItem("打开", "Ctrl+O", false, true))
			{
			}
			if (ImGui::MenuItem("保存", "Ctrl+S", false, true))
			{
			}
			if (ImGui::MenuItem("另存为...", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("关闭", nullptr, false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("退出", "Ctrl+Q", false, true))
			{
			}
			ImGui::EndMenu();
		}
	}
}