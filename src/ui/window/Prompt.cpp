#include <cstring>
#include <imgui.h>
#include "Prompt.h"

constexpr auto BUF_SIZE = 100;

namespace fwlab::ui::window
{
	Prompt::Prompt(std::string name, std::string value, std::string title)
	{
		this->name = name;
		this->value = value;
		this->title = title;
	}

	Prompt::~Prompt()
	{

	}

	void Prompt::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0), ImGuiCond_Once);
		ImGui::SetNextWindowSize(ImVec2(width, height));

		if (ImGui::Begin(title.c_str(), &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			if (ImGui::BeginChild("Prompt Content", ImVec2(width, 80)), true)
			{
				char buf[BUF_SIZE] = {};
				std::strcpy(buf, value.c_str());
				ImGui::Text(name.c_str());
				ImGui::SameLine();
				ImGui::InputText("", buf, BUF_SIZE);
				if (std::strcmp(buf, value.c_str()) != 0)
				{
					value.assign(buf);
				}
			}
			ImGui::EndChild();

			ImGui::Spacing();
			ImGui::SameLine(width - 80);
			if (ImGui::Button("确认", ImVec2(64, 28)))
			{
				isOpen = false;
				if (callback)
				{
					callback(value, this);
				}
			}
		}

		ImGui::End();
	}

	void Prompt::setCallback(std::function<void(std::string, Prompt* view)> callback)
	{
		this->callback = callback;
	}
}