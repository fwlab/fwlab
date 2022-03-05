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
		trainMenu = new TrainMenu();
		experimentMenu = new ExperimentMenu();
		optionsMenu = new OptionsMenu();
		helpMenu = new HelpMenu();
	}

	MenuBar::~MenuBar()
	{
		delete fileMenu;
		delete editMenu;
		delete objectMenu;
		delete lightMenu;
		delete trainMenu;
		delete experimentMenu;
		delete optionsMenu;
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
			trainMenu->render();
			experimentMenu->render();
			optionsMenu->render();
			helpMenu->render();

			ImGui::EndMainMenuBar();
		}
	}
}
