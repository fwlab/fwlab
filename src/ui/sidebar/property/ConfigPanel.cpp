#include <string.h>
#include <imgui.h>
#include "ConfigPanel.h"

namespace fwlab::ui::sidebar::property
{
	ConfigPanel::ConfigPanel()
	{

	}

	ConfigPanel::~ConfigPanel()
	{
	}

	void ConfigPanel::render()
	{
		if (ImGui::CollapsingHeader("基本信息"))
		{
			char sceneName[20] = "场景";
			ImGui::InputText("名称", sceneName, 20);
			ImGui::InputText("类型", sceneName, 20);
		}
		if (ImGui::CollapsingHeader("位移组件"))
		{
			static float vec4a[4] = { 0.10f, 0.20f, 0.30f, 0.44f };
			ImGui::InputFloat3("位置", vec4a);
			ImGui::InputFloat3("旋转", vec4a);
			ImGui::InputFloat3("缩放", vec4a);
		}
		if (ImGui::CollapsingHeader("场景组件"))
		{
			float col[3] = { 1, 0, 0 };
			ImGui::ColorEdit3("背景", col);
		}
	}
}