#include <imgui.h>
#include "ObjectMenu.h"

namespace fwlab::ui::menubar
{
	void ObjectMenu::render()
	{
		if (ImGui::BeginMenu("物体", true))
		{
			if (ImGui::BeginMenu("几何体", true))
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

			if (ImGui::BeginMenu("光源", true))
			{
				if (ImGui::MenuItem("环境光", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("点光源", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("平行光", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("聚光灯", nullptr, false, true))
				{
				}
				if (ImGui::MenuItem("半球光", nullptr, false, true))
				{
				}
				ImGui::EndMenu();
			}

			ImGui::EndMenu();
		}
	}
}
