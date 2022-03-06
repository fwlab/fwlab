#ifndef FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#define FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#include "../Component.h"

namespace fwlab::ui::dialog
{
	class OpenFileDialog : public Component
	{
	public:
		OpenFileDialog();
		virtual ~OpenFileDialog();
		void render() override;
	};
}

#endif