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
			ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Once);
		}

		ImGui::Begin("保存文件", &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

		ImGui::AlignTextToFramePadding();
		ImGui::Text("路径"); ImGui::SameLine();
		ImGui::LabelText("", "C:\\Window\\");

		float winWidth = ImGui::GetWindowContentRegionWidth();

		ImGui::BeginChildFrame(ImGui::GetID("SaveFileDialog_frame"), ImVec2(winWidth, height - 105), ImGuiWindowFlags_NoMove);

		ImGui::Text("文件列表");

		ImGui::EndChildFrame();

		ImGui::Spacing();
		ImGui::SameLine(winWidth - 148);
		if (ImGui::Button("确认", ImVec2(64, 28)))
		{

		}
		ImGui::SameLine();
		if (ImGui::Button("取消", ImVec2(64, 28)))
		{

		}

		ImGui::End();
	}

	void SaveFileDialog::setSaveCallback(std::function<void(std::string path)> callback)
	{
		this->callback = callback;
	}
}