#include <imgui.h>
#include "LightMenu.h"

namespace fwlab::ui::menubar
{
	void LightMenu::render()
	{
		if (ImGui::BeginMenu("光源", true))
		{
			if (ImGui::MenuItem("环境光", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("平行光", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("点光源", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("聚光灯", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("半球光", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("矩形光", nullptr, false, true))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("点光源帮助器", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("半球光帮助器", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("矩形光帮助器", nullptr, false, true))
			{
			}
			ImGui::EndMenu();
		}
	}
}