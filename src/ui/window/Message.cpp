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

		ImGui::SetNextWindowPos(ImVec2((size.x - width) / 2.0, (size.y - height) / 2.0));
		ImGui::SetNextWindowSize(ImVec2(width, height));

		if (ImGui::Begin(title.c_str(), &isOpen, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			ImGui::Text(content.c_str());
			ImGui::End();
		}

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