#ifndef FWLAB_UI_MENUBAR_FILE_MENU_H
#define FWLAB_UI_MENUBAR_FILE_MENU_H
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class FileMenu : public Component
	{
	public:
		void render() override;
	};
}

#endif