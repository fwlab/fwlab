#include <imgui.h>
#include "SideBar.h"

using namespace ui::sidebar;

SideBar::SideBar()
{
	scenePanel = new scene::ScenePanel();
}

SideBar::~SideBar()
{
	delete scenePanel;
}

void SideBar::render()
{
	float top = 26;

	ImGui::SetNextWindowPos(ImVec2(0, top));

	ImVec2 size = ImGui::GetIO().DisplaySize;

	ImGui::SetNextWindowSize(ImVec2(size.x, size.y - top), ImGuiCond_Once);
	ImGui::SetNextWindowSizeConstraints(ImVec2(20, size.y - top), ImVec2(width, size.y - top));

	if (ImGui::Begin("SideBar", nullptr, ImGuiWindowFlags_NoTitleBar))
	{
		scenePanel->render();

		ImGui::End();
	}
}