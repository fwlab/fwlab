#ifndef FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#define FWLAB_UI_DIALOG_OPEN_FILE_DIALOG_H
#include <functional>
#include <string>
#include "../Component.h"

namespace fwlab::ui::dialog
{
	class OpenFileDialog : public Component
	{
	public:
		OpenFileDialog();
		virtual ~OpenFileDialog();
		void open();
		void close();
		void render() override;
		void setSaveCallback(std::function<void(std::string path)> callback);

	private:
		std::function<void(std::string path)> callback = nullptr;
		float width = 800;
		float height = 400;
		bool isOpen = false;
		std::string selectedDriver = "";
	};
}

#endif