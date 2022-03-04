#include <imgui.h>
#include "OptionsMenu.h"

namespace fwlab::ui::menubar
{
	void OptionsMenu::render()
	{
		if (ImGui::BeginMenu("选项", true))
		{
			if (ImGui::MenuItem("训练", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("设置", nullptr, false, true))
			{
			}

			ImGui::EndMenu();
		}
	}
}