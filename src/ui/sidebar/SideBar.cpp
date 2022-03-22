#include <imgui.h>
#include "SideBar.h"

namespace fwlab::ui::sidebar
{
	SideBar::SideBar()
	{
		scenePanel = new scene::ScenePanel();
		propertyPanel = new property::PropertyPanel();
	}

	SideBar::~SideBar()
	{
		delete scenePanel;
		delete propertyPanel;
	}

	void SideBar::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		// SideBar
		float height = size.y - marginTop;
		ImGui::SetNextWindowPos(ImVec2(0, marginTop));
		ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Once);
		ImGui::SetNextWindowSizeConstraints(ImVec2(width, height), ImVec2(maxWidth, height));

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);

		ImGui::Begin("SideBar", nullptr, ImGuiWindowFlags_NoTitleBar);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1);

		// Scene Panel
		if (ImGui::BeginChild("ScenePanel", ImVec2(width, sceneHeight)))
		{
			scenePanel->render();
		}
		ImGui::EndChild();

		// Property Panel
		if (ImGui::BeginChild("PropertyPanel", ImVec2(width, height - sceneHeight - 24)))
		{
			propertyPanel->render();
		}
		ImGui::EndChild();

		ImGui::PopStyleVar();

		ImGui::End();

		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
	}
}