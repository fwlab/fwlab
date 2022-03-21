#include <imgui.h>
#include "OpenFileDialog.h"
#include "../../context/context.h"
#include "../../event/EventList.h"

namespace fwlab::ui::dialog
{
	OpenFileDialog::OpenFileDialog()
	{

	}

	OpenFileDialog::~OpenFileDialog()
	{

	}

	void OpenFileDialog::open()
	{

	}

	void OpenFileDialog::close()
	{

	}

	void OpenFileDialog::render()
	{
		if (!isOpen)
		{
			return;
		}

		ImVec2 size = ImGui::GetIO().DisplaySize;

		ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0), ImGuiCond_Appearing);
		ImGui::SetNextWindowSize(ImVec2(width, height));

		ImGui::Begin("打开文件", &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_Modal);

		ImGui::Text("你好");

		ImGui::End();
	}

	void OpenFileDialog::setSaveCallback(std::function<void(std::string path)> callback)
	{
		this->callback = callback;
	}
}