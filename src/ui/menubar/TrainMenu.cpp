#include <imgui.h>
#include "TrainMenu.h"

namespace fwlab::ui::menubar
{
	void TrainMenu::render()
	{
		if (ImGui::BeginMenu("训练", true))
		{
			if (ImGui::MenuItem("训练", nullptr, false, true))
			{
			}
			if (ImGui::MenuItem("模拟", nullptr, false, true))
			{
			}

			ImGui::EndMenu();
		}
	}
}