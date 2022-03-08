#ifndef FWLAB_EDITOR_H
#define FWLAB_EDITOR_H
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "ui/Component.h"
#include "ui/UIHelper.h"
#include "ui/window/Message.h"
#include "ui/window/Confirm.h"
#include "ui/window/Prompt.h"
#include "ui/menubar/MenuBar.h"
#include "ui/sidebar/SideBar.h"
#include "ui/framerate/Framerate.h"

namespace fwlab
{
	class Editor final : public ui::Component
	{
	public:
		Editor();
		virtual ~Editor();
		void render() override;
		void info(std::string content, std::string title = "消息");
		void success(std::string content, std::string title = "成功");
		void warn(std::string content, std::string title = "警告");
		void error(std::string content, std::string title = "错误");
		void confirm(std::string content, std::function<void(bool)> callback, std::string title = "询问");
		void prompt(std::string content, std::function<void(std::string)> callback, std::string value = "", std::string title = "请输入");

	private:
		void showMessage(std::string content, std::string title, ui::window::Message::MessageType type);
		ui::UIHelper* ui = nullptr;
		std::vector<std::unique_ptr<ui::window::Message>> messages;
		std::vector<std::unique_ptr<ui::window::Confirm>> confirms;
		std::function<void(bool)> confirmCallback = nullptr;
		std::vector<std::unique_ptr<ui::window::Prompt>> prompts;
		ui::menubar::MenuBar* menubar;
		ui::sidebar::SideBar* sidebar;
		ui::framerate::Framerate* framerate;
	};
}

#endif