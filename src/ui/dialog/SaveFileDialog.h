#ifndef FWLAB_UI_DIALOG_SAVE_FILE_DIALOG_H
#define FWLAB_UI_DIALOG_SAVE_FILE_DIALOG_H
#include <functional>
#include <string>
#include <concurrent_vector.h>
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
		void addExtension(std::string extension, std::string label);
		void removeExtension(std::string extension);

	private:
		void renderDriver(float left, float width, float height);
		void renderFileList(float left, float width, float height);
		void selectDriver(std::string disk);
		void selectDirectory(std::string path);

		// 文件扩展名
		using FileExtension = struct {
			std::string extension;
			std::string label;
		};

		std::function<void(std::string path)> callback = nullptr;
		float width = 800;
		float height = 400;
		bool isOpen = false;
		bool shouldSetWindow = false;

		std::string currentPath;
		std::string fileName;
		std::vector<FileExtension> extensions;
		int currentExtensionIndex = 0;

		std::vector<std::string> disks;
		std::string selectedDriver;

		std::vector<std::string> children;
	};
}

#endif