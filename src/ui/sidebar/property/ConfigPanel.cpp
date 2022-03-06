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

			ImGui::AlignTextToFramePadding();
			ImGui::Text("名称"); ImGui::SameLine();
			ImGui::InputText("", sceneName, 20);

			ImGui::AlignTextToFramePadding();
			ImGui::Text("类型"); ImGui::SameLine();
			ImGui::InputText("", sceneName, 20);
		}
		if (ImGui::CollapsingHeader("位移组件"))
		{
			static float vec4a[4] = { 0.10f, 0.20f, 0.30f, 0.44f };

			ImGui::AlignTextToFramePadding();
			ImGui::Text("位置"); ImGui::SameLine();
			ImGui::InputFloat3("", vec4a);

			ImGui::AlignTextToFramePadding();
			ImGui::Text("旋转"); ImGui::SameLine();
			ImGui::InputFloat3("", vec4a);

			ImGui::AlignTextToFramePadding();
			ImGui::Text("旋转"); ImGui::SameLine();
			ImGui::InputFloat3("", vec4a);
		}
		if (ImGui::CollapsingHeader("场景组件"))
		{
			float col[3] = { 1, 0, 0 };
			ImGui::AlignTextToFramePadding();
			ImGui::Text("背景"); ImGui::SameLine();
			ImGui::ColorEdit3("", col);
		}
	}
}