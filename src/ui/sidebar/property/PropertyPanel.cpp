#include <imgui.h>
#include "PropertyPanel.h"

namespace fwlab::ui::sidebar::property
{
	PropertyPanel::PropertyPanel()
	{
		configPanel = new ConfigPanel();
		scriptPanel = new ScriptPanel();
	}

	PropertyPanel::~PropertyPanel()
	{
		delete configPanel;
		delete scriptPanel;
	}

	void PropertyPanel::render()
	{
		isConfigTabShow = false;
		isScriptTabShow = false;

		if (ImGui::BeginTabBar("property-tab"))
		{
			if (ImGui::BeginTabItem("属性"))
			{
				isConfigTabShow = true;
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("脚本"))
			{
				isScriptTabShow = true;
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}

		if (isConfigTabShow)
		{
			configPanel->render();
		}

		if (isScriptTabShow)
		{
			scriptPanel->render();
		}
	}
}