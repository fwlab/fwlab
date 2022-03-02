#include <imgui.h>
#include "ScriptPanel.h"

namespace fwlab::ui::sidebar::property
{
	ScriptPanel::ScriptPanel()
	{

	}

	ScriptPanel::~ScriptPanel()
	{
	}

	void ScriptPanel::render()
	{
		ImGui::Text("Script Panel");
	}
}