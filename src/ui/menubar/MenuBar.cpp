#include <imgui.h>
#include "MenuBar.h"

namespace fwlab::ui::menubar
{
	MenuBar::MenuBar()
	{
		fileMenu = new FileMenu();
		editMenu = new EditMenu();
		objectMenu = new ObjectMenu();
		lightMenu = new LightMenu();
		helpMenu = new HelpMenu();
	}

	MenuBar::~MenuBar()
	{
		delete fileMenu;
		delete editMenu;
		delete objectMenu;
		delete lightMenu;
		delete helpMenu;
	}

	void MenuBar::render()
	{
		if (ImGui::BeginMainMenuBar())
		{
			fileMenu->render();
			editMenu->render();
			objectMenu->render();
			lightMenu->render();
			helpMenu->render();

			ImGui::EndMainMenuBar();
		}
	}
}
