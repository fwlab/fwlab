#ifndef FWLAB_UI_MENUBAR_OPTIONS_MENU_H
#define FWLAB_UI_MENUBAR_OPTIONS_MENU_H
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class OptionsMenu : public Component
	{
	public:
		void render() override;
	};
}

#endif