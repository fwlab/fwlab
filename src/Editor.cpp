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
		openDialog = new ui::dialog::OpenFileDialog();
		saveDialog = new ui::dialog::SaveFileDialog();
	}

	Editor::~Editor()
	{
		delete menubar;
		delete sidebar;
		delete framerate;
		delete openDialog;
		delete saveDialog;
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

		openDialog->render();
		saveDialog->render();
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
		confirmCallback = callback;

		auto confirm = new ui::window::Confirm(content, title);
		confirm->setCallback([&](bool isOK, ui::window::Confirm* view) {
			auto index = std::find_if(confirms.begin(), confirms.end(), [&](auto& confirm) {
				return confirm.get() == view;
				});
			if (index != confirms.end())
			{
				if (confirmCallback)
				{
					confirmCallback(isOK);

				}
				confirms.erase(index);
			}
			});
		confirms.push_back(std::make_unique<ui::window::Confirm>(*confirm));
	}

	void Editor::prompt(std::string name, std::function<void(std::string)> callback, std::string value, std::string title)
	{
		promptCallback = callback;

		auto prompt = new ui::window::Prompt(name, value, title);
		prompt->setCallback([&](std::string value, ui::window::Prompt* view) {
			auto index = std::find_if(prompts.begin(), prompts.end(), [&](auto& prompt) {
				return prompt.get() == view;
				});
			if (index != prompts.end())
			{
				if (promptCallback)
				{
					promptCallback(value);
				}
				prompts.erase(index);
			}
			});
		prompts.push_back(std::make_unique<ui::window::Prompt>(*prompt));
	}

	void Editor::openFile(std::function<void(std::string)> callback)
	{
		openDialog->setSaveCallback(callback);
		openDialog->open();
	}

	void Editor::saveFile(std::function<void(std::string)> callback)
	{
		saveDialog->setSaveCallback(callback);
		saveDialog->open();
	}
}
