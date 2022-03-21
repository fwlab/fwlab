#ifndef FWLAB_UI_DIALOG_SAVE_FILE_DIALOG_H
#define FWLAB_UI_DIALOG_SAVE_FILE_DIALOG_H
#include <functional>
#include <string>
#include "../Component.h"

namespace fwlab::ui::dialog
{
	class SaveFileDialog : public Component
	{
	public:
		SaveFileDialog();
		virtual ~SaveFileDialog();
		void open();
		void close();
		void render() override;
		void setSaveCallback(std::function<void(std::string path)> callback);

	private:
		std::function<void(std::string path)> callback = nullptr;
		float width = 800;
		float height = 400;
		bool isOpen = false;
		bool shouldSetWindow = false;
	};
}

#endif