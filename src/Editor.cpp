#include <algorithm>
#include <imgui.h>
#include "Editor.h"

namespace fwlab
{
	Editor::Editor()
	{
		ui = new ui::UIHelper();

		ImGui::GetStyle().WindowRounding = 0;
		ImGui::GetStyle().WindowBorderSize = 0;

		ui->setCallback([&]()
			{ render(); });

		menubar = new ui::menubar::MenuBar();
		sidebar = new ui::sidebar::SideBar();
		framerate = new ui::framerate::Framerate();
	}

	Editor::~Editor()
	{
		delete menubar;
		delete sidebar;
		delete framerate;
		delete ui;
	}

	void Editor::render()
	{
		menubar->render();
		sidebar->render();
		framerate->render();

		for (auto& message : messages)
		{
			message->render();
		}
		for (auto& confirm : confirms)
		{
			confirm->render();
		}
		for (auto& prompt : prompts)
		{
			prompt->render();
		}
	}

	void Editor::info(std::string content, std::string title)
	{
		showMessage(content, title, ui::window::Message::MessageType::INFO);
	}

	void Editor::success(std::string content, std::string title)
	{
		showMessage(content, title, ui::window::Message::MessageType::SUCCESS);
	}

	void Editor::warn(std::string content, std::string title)
	{
		showMessage(content, title, ui::window::Message::MessageType::WARN);
	}

	void Editor::error(std::string content, std::string title)
	{
		showMessage(content, title, ui::window::Message::MessageType::ERROR);
	}

	void Editor::showMessage(std::string content, std::string title, ui::window::Message::MessageType type)
	{
		auto message = new ui::window::Message(content, type, title);
		message->setCloseCallback([&](ui::window::Message* view) {
			auto index = std::find_if(messages.begin(), messages.end(), [&](auto& message) {
				return message.get() == view;
				});
			if (index != messages.end())
			{
				messages.erase(index);
			}
			});
		messages.push_back(std::make_unique<ui::window::Message>(*message));
	}

	void Editor::confirm(std::string content, std::function<void(bool)> callback, std::string title)
	{
		auto confirm = new ui::window::Confirm(content, title);
		confirm->setOKCallback([&](ui::window::Confirm* view) {
			auto index = std::find_if(confirms.begin(), confirms.end(), [&](auto& confirm) {
				return confirm.get() == view;
				});
			if (index != confirms.end())
			{
				confirms.erase(index);
			}
			if (callback)
			{
				callback(true);
			}
			});
		confirm->setCancelCallback([&](ui::window::Confirm* view) {
			auto index = std::find_if(confirms.begin(), confirms.end(), [&](auto& confirm) {
				return confirm.get() == view;
				});
			if (index != confirms.end())
			{
				confirms.erase(index);
			}
			if (callback)
			{
				callback(false);
			}
			});
		confirms.push_back(std::make_unique<ui::window::Confirm>(*confirm));
	}

	void Editor::prompt(std::string content, std::function<void(std::string)> callback, std::string value, std::string title)
	{

	}
}
