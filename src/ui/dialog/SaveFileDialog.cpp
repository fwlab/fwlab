#include <imgui.h>
#include "SaveFileDialog.h"
#include "../../context/context.h"
#include "../../event/EventList.h"

namespace fwlab::ui::dialog
{
	SaveFileDialog::SaveFileDialog()
	{

	}

	SaveFileDialog::~SaveFileDialog()
	{

	}

	void SaveFileDialog::open()
	{
		isOpen = true;
		shouldSetWindow = true;
	}

	void SaveFileDialog::close()
	{
		isOpen = false;
	}

	void SaveFileDialog::render()
	{
		if (!isOpen)
		{
			return;
		}

		if (shouldSetWindow)
		{
			shouldSetWindow = false;

			ImVec2 size = ImGui::GetIO().DisplaySize;
			ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0));
			ImGui::SetNextWindowSize(ImVec2(width, height));
		}

		ImGui::Begin("保存文件", &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_Modal);

		ImGui::Text("你好");

		ImGui::End();
	}

	void SaveFileDialog::setSaveCallback(std::function<void(std::string path)> callback)
	{
		this->callback = callback;
	}
}