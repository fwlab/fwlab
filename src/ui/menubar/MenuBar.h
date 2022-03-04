#ifndef FWLAB_UI_MENUBAR_MENU_BAR_H
#define FWLAB_UI_MENUBAR_MENU_BAR_H
#include "../Component.h"
#include "FileMenu.h"
#include "EditMenu.h"
#include "ObjectMenu.h"
#include "LightMenu.h"
#include "TrainMenu.h"
#include "OptionsMenu.h"
#include "HelpMenu.h"

namespace fwlab::ui::menubar
{
	class MenuBar : public Component
	{
	public:
		MenuBar();
		virtual ~MenuBar();
		void render() override;

	private:
		FileMenu* fileMenu = nullptr;
		EditMenu* editMenu = nullptr;
		ObjectMenu* objectMenu = nullptr;
		LightMenu* lightMenu = nullptr;
		TrainMenu* trainMenu = nullptr;
		OptionsMenu* optionsMenu = nullptr;
		HelpMenu* helpMenu = nullptr;
	};
}

#endif