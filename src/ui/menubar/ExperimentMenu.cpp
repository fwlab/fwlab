#include <imgui.h>
#include "ExperimentMenu.h"

namespace fwlab::ui::menubar
{
	void ExperimentMenu::render()
	{
		if (ImGui::BeginMenu("实验", true))
		{
			if (ImGui::MenuItem("机器狗动作", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("机器狗视觉", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("机器狗听觉", nullptr, false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("语言学习", nullptr, false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("生物进化", nullptr, false, true))
			{
			}
			ImGui::EndMenu();
		}
	}
}