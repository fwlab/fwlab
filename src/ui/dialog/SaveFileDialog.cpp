#include <filesystem>
#include <imgui.h>
#include "SaveFileDialog.h"
#include "../../context/context.h"
#include "../../event/EventList.h"
#include "../../utils/SystemUtils.h"

namespace fwlab::ui::dialog
{
	SaveFileDialog::SaveFileDialog()
	{
		disks = utils::SystemUtils::GetLogicalDrives();

		selectedDriver = disks[0];
		currentPath = selectedDriver + ":\\";
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

		// 当前路径
		ImGui::AlignTextToFramePadding();
		ImGui::Text("路径"); ImGui::SameLine();
		ImGui::LabelText("", currentPath.c_str());

		// 驱动器和文件列表
		float contentWidth = ImGui::GetWindowContentRegionWidth();
		float frameHeight = height - 105;
		float spacing = 4;

		renderDriver(0, 240, frameHeight);
		ImGui::SameLine(0, spacing);
		renderFileList(240 + spacing, contentWidth - 240 - spacing, frameHeight);


		// 按钮
		ImGui::Spacing();
		ImGui::SameLine(contentWidth - 148);
		if (ImGui::Button("确认", ImVec2(64, 28)))
		{
			isOpen = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("取消", ImVec2(64, 28)))
		{
			isOpen = false;
		}

		ImGui::End();
	}

	void SaveFileDialog::renderDriver(float left, float width, float height)
	{
		ImGui::BeginChild("SaveFileDialog::renderDriver", ImVec2(width, height), true);

		ImGui::Text("驱动器列表");

		for (auto& disk : disks)
		{
			if (ImGui::Selectable(disk.c_str(), disk == selectedDriver))
			{
				selectDriver(disk);
			}
		}

		ImGui::EndChild();
	}

	void SaveFileDialog::selectDriver(std::string disk)
	{
		selectedDriver = disk;
		currentPath = disk + ":\\";
	}

	void SaveFileDialog::renderFileList(float left, float width, float height)
	{
		ImGui::BeginChild("SaveFileDialog::renderFileList", ImVec2(width, height), true);

		ImGui::Text("文件列表");

		ImGui::EndChild();
	}

	void SaveFileDialog::setSaveCallback(std::function<void(std::string path)> callback)
	{
		this->callback = callback;
	}
}