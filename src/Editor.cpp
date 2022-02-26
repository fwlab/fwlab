#include <imgui.h>
#include "Editor.h"

Editor::Editor()
{
	ImGui::GetStyle().WindowRounding = 0;
	ImGui::GetStyle().WindowBorderSize = 0;

	menubar = new ui::menubar::MenuBar();
	sidebar = new ui::sidebar::SideBar();
	framerate = new ui::framerate::Framerate();
}

Editor::~Editor()
{
	delete menubar;
	delete sidebar;
	delete framerate;
}

void Editor::render()
{
	menubar->render();
	sidebar->render();
	framerate->render();
}
