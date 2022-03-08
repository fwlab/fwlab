#include <imgui.h>
#include "Message.h"

namespace fwlab::ui::window
{
	Message::Message(std::string content, MessageType type, std::string title)
	{
		this->content = content;
		this->type = type;
		this->title = title;
	}

	Message::~Message()
	{

	}

	void Message::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0), ImGuiCond_Once);
		ImGui::SetNextWindowSize(ImVec2(width, height));

		if (type == MessageType::SUCCESS)
		{
			ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(103.0 / 255, 194.0 / 255, 58.0 / 255, 1));
			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(103.0 / 255, 194.0 / 255, 58.0 / 255, 1));
		}
		else if (type == MessageType::WARN)
		{
			ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(230.0 / 255, 162.0 / 255, 60.0 / 255, 1));
			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(230.0 / 255, 162.0 / 255, 60.0 / 255, 1));
		}
		else if (type == MessageType::ERROR)
		{
			ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(245.0 / 255, 108.0 / 255, 108.0 / 255, 1));
			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(245.0 / 255, 108.0 / 255, 108.0 / 255, 1));
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(64.0 / 255, 158.0 / 255, 255.0 / 255, 1));
			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(64.0 / 255, 158.0 / 255, 255.0 / 255, 1));
		}

		if (ImGui::Begin(title.c_str(), &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			if (ImGui::BeginChild("Message Content", ImVec2(width, 80)), true)
			{
				ImGui::Text(content.c_str());
			}
			ImGui::EndChild();

			ImGui::Spacing();
			ImGui::SameLine(width - 80);
			if (ImGui::Button("关闭", ImVec2(64, 28)))
			{
				isOpen = false;
			}
		}

		ImGui::End();

		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

		if (!isOpen && callback)
		{
			callback(this);
		}
	}

	void Message::setCloseCallback(std::function<void(Message* view)> callback)
	{
		this->callback = callback;
	}
}