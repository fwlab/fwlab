#ifndef FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#define FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#include "../Component.h"

namespace fwlab::ui::dialog
{
	class SaveFileDialog : public Component
	{
	public:
		SaveFileDialog();
		virtual ~SaveFileDialog();
		void render() override;
	};
}

#endif