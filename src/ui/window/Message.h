#ifndef FWLAB_UI_WINDOW_MESSAGE_H
#define FWLAB_UI_WINDOW_MESSAGE_H
#include <functional>
#include <string>
#include "../Component.h"

namespace fwlab::ui::window
{
	class Message : public Component
	{
	public:
		enum class MessageType
		{
			INFO,
			SUCCESS,
			WARN,
			ERROR
		};
		Message(std::string content, MessageType type, std::string title = "消息");
		virtual ~Message();
		void render() override;
		void setCloseCallback(std::function<void(Message* view)> callback);

	private:
		std::string content;
		MessageType type;
		std::string title;
		float width = 320;
		float height = 160;
		std::function<void(Message* view)> callback = nullptr;
		bool isOpen = true;
	};
}

#endif