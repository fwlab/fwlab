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
		ImGui::Text("Config Panel");
	}
}