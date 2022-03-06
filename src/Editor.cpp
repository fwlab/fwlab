#include <imgui.h>
#include "Editor.h"

namespace fwlab
{
	Editor::Editor()
	{
		ui = new ui::UIHelper();

		ImGui::GetStyle().WindowRounding = 0;
		ImGui::GetStyle().WindowBorderSize = 0;

		ui->setCallback([&]()
			{ render(); });

		menubar = new ui::menubar::MenuBar();
		sidebar = new ui::sidebar::SideBar();
		framerate = new ui::framerate::Framerate();
	}

	Editor::~Editor()
	{
		delete menubar;
		delete sidebar;
		delete framerate;
		delete ui;
	}

	void Editor::render()
	{
		menubar->render();
		sidebar->render();
		framerate->render();
	}

	void Editor::info(std::string content, std::string title)
	{

	}

	void Editor::success(std::string content, std::string title)
	{

	}

	void Editor::warn(std::string content, std::string title)
	{

	}

	void Editor::error(std::string content, std::string title)
	{

	}

	void Editor::confirm(std::string content, std::function<void(bool)> callback, std::string title)
	{

	}

	void Editor::prompt(std::string content, std::function<void(std::string)> callback, std::string value, std::string title)
	{

	}
}
