#include <imgui.h>
#include "ScenePanel.h"

namespace fwlab::ui::sidebar::scene
{
	ScenePanel::ScenePanel()
	{
		hirarchyPanel = new HirarchyPanel();
		historyPanel = new HistoryPanel();
	}

	ScenePanel::~ScenePanel()
	{
		delete hirarchyPanel;
		delete historyPanel;
	}

	void ScenePanel::render()
	{
		isSceneTabShow = false;
		isHistoryTabShow = false;

		if (ImGui::BeginTabBar("scene-tab"))
		{
			if (ImGui::BeginTabItem("场景"))
			{
				isSceneTabShow = true;
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("历史"))
			{
				isHistoryTabShow = true;
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}

		if (isSceneTabShow)
		{
			hirarchyPanel->render();
		}

		if (isHistoryTabShow)
		{
			historyPanel->render();
		}
	}
}