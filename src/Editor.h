#ifndef FWLAB_EDITOR_H
#define FWLAB_EDITOR_H
#include <functional>
#include <string>
#include "ui/Component.h"
#include "ui/UIHelper.h"
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
		ui::UIHelper* ui = nullptr;
		ui::menubar::MenuBar* menubar;
		ui::sidebar::SideBar* sidebar;
		ui::framerate::Framerate* framerate;
	};
}

#endif