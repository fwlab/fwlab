#include <imgui.h>
#include "Confirm.h"

namespace fwlab::ui::window
{
	Confirm::Confirm(std::string content, std::string title)
	{
		this->content = content;
		this->title = title;
	}

	Confirm::~Confirm()
	{

	}

	void Confirm::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		isOK = false;

		ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0), ImGuiCond_Once);
		ImGui::SetNextWindowSize(ImVec2(width, height));

		if (ImGui::Begin(title.c_str(), &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			if (ImGui::BeginChild("Confirm Content", ImVec2(width, 80)), true)
			{
				ImGui::Text(content.c_str());
			}
			ImGui::EndChild();

			ImGui::Spacing();
			ImGui::SameLine(width - 152);
			if (ImGui::Button("确认", ImVec2(64, 28)))
			{
				isOpen = false;
				isOK = true;
			}
			ImGui::SameLine();
			if (ImGui::Button("取消", ImVec2(64, 28)))
			{
				isOpen = false;
			}
		}

		ImGui::End();

		if (!isOpen && callback)
		{
			callback(isOK, this);
		}
	}

	void Confirm::setCallback(std::function<void(bool, Confirm* view)> callback)
	{
		this->callback = callback;
	}
}