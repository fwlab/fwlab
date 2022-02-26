#include <imgui.h>
#include "HelpMenu.h"

namespace fwlab::ui::menubar
{

	void HelpMenu::render()
	{
		if (ImGui::BeginMenu("帮助", true))
		{
			if (ImGui::MenuItem("演示窗口", nullptr, false, true))
			{
				isDemoWindowShow = true;
			}
			if (ImGui::MenuItem("矩阵窗口", nullptr, false, true))
			{
				isMetricsWindowShow = true;
			}
			if (ImGui::MenuItem("关于窗口", nullptr, false, true))
			{
				isAboutWindowShow = true;
			}
			ImGui::EndMenu();
		}

		// 演示窗口
		if (isDemoWindowShow)
		{
			ImGui::ShowDemoWindow(&isDemoWindowShow);
		}

		// 矩阵窗口
		if (isMetricsWindowShow)
		{
			ImGui::ShowMetricsWindow(&isMetricsWindowShow);
		}

		// 关于窗口
		if (isAboutWindowShow)
		{
			ImGui::ShowAboutWindow(&isAboutWindowShow);
		}
	}
}