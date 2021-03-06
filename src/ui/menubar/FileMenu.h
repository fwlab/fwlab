#ifndef FWLAB_UI_MENUBAR_FILE_MENU_H
#define FWLAB_UI_MENUBAR_FILE_MENU_H
#include <string>
#include "../Component.h"

namespace fwlab::ui::menubar
{
	class FileMenu : public Component
	{
	public:
		FileMenu();
		virtual ~FileMenu();
		void render() override;
		void handleNew();
		void handleOpen();
		void handleSave();
		void handleSaveAs();
		void handleClose();
		void handleExit();
	};
}

#endif