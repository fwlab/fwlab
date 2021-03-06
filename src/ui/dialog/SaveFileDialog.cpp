#include <cstring>
#include <filesystem>
#include <imgui.h>
#include "SaveFileDialog.h"
#include "../../context/context.h"
#include "../../event/EventList.h"
#include "../../utils/DirectoryUtils.h"

constexpr int BUF_SIZE = 255;

namespace fwlab::ui::dialog
{
	SaveFileDialog::SaveFileDialog()
	{
		disks = utils::DirectoryUtils::GetLogicalDrives();

		selectedDriver = disks[0];
		currentPath = selectedDriver + ":\\";
		extensions.push_back(FileExtension{ .extension = "",.label = "所有文件" });
		extensions.push_back(FileExtension{ .extension = ".txt",.label = "文本" });
		extensions.push_back(FileExtension{ .extension = ".jpg",.label = "图片" });

		auto subs = utils::DirectoryUtils::GetChildren(currentPath);
		auto& write = children.getWrite();
		write.insert(write.end(), subs.begin(), subs.end());
		children.swap();
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

		// 文件名
		ImGui::AlignTextToFramePadding();
		ImGui::Text("文件名"); ImGui::SameLine();

		char buf[BUF_SIZE] = "";
		std::strncpy(buf, fileName.c_str(), BUF_SIZE);

		ImGui::SetNextItemWidth(contentWidth - 320);
		if (ImGui::InputText("", buf, BUF_SIZE))
		{
			fileName = buf;
		}

		// 后缀
		ImGui::SameLine();
		ImGui::SetNextItemWidth(120);
		auto& currentExtension = extensions.at(currentExtensionIndex);
		if (ImGui::BeginCombo("", currentExtension.label.c_str()))
		{
			for (int i = 0; i < extensions.size(); i++)
			{
				auto& extension = extensions.at(i);
				if (ImGui::Selectable(extension.label.c_str(), currentExtensionIndex == i))
				{
					currentExtensionIndex = i;
				}
			}

			ImGui::EndCombo();
		}

		// 按钮
		ImGui::SameLine();
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

		auto subs = utils::DirectoryUtils::GetChildren(currentPath);
		auto& write = children.getWrite();
		write.clear();
		write.insert(write.end(), subs.begin(), subs.end());
		children.swap();
	}

	void SaveFileDialog::renderFileList(float left, float width, float height)
	{
		ImGui::BeginChild("SaveFileDialog::renderFileList", ImVec2(width, height), true);

		auto& read = children.getRead();
		for (auto i = 0; i < read.size(); i++)
		{
			auto& child = read.at(i);
			if (ImGui::Selectable(child.c_str()))
			{
				selectDirectory(child);
			}
		}

		ImGui::EndChild();
	}

	void SaveFileDialog::selectDirectory(std::string path)
	{
		currentPath += path;

		auto subs = utils::DirectoryUtils::GetChildren(currentPath);
		auto& write = children.getWrite();
		write.clear();
		write.insert(write.end(), subs.begin(), subs.end());
		children.swap();
	}

	void SaveFileDialog::setSaveCallback(std::function<void(std::string path)> callback)
	{
		this->callback = callback;
	}

	void SaveFileDialog::addExtension(std::string extension, std::string label)
	{
		extensions.push_back(FileExtension{ .extension = extension, .label = label });
	}

	void SaveFileDialog::removeExtension(std::string extension)
	{
		auto pred = [&](FileExtension& ext)
		{ return ext.extension == extension; };
		extensions.erase(std::find_if(extensions.begin(), extensions.end(), pred));
	}
}