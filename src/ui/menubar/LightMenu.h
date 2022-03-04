#ifndef FWLAB_UI_MENUBAR_LIGHT_MENU_H
#define FWLAB_UI_MENUBAR_LIGHT_MENU_H
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class LightMenu : public Component
	{
	public:
		void render() override;
	};
}

#endif