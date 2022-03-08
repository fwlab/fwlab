#ifndef FWLAB_UI_WINDOW_PROMPT_H
#define FWLAB_UI_WINDOW_PROMPT_H
#include <functional>
#include <string>
#include "../Component.h"

namespace fwlab::ui::window
{
	class Prompt : public Component
	{
	public:
		Prompt(std::string name, std::string value = "", std::string title = "«Î ‰»Î");
		virtual ~Prompt();
		void render() override;
		void setCallback(std::function<void(std::string, Prompt* view)> callback);

	private:
		std::string name;
		std::string value;
		std::string title;
		float width = 320;
		float height = 160;
		std::function<void(std::string, Prompt* view)> callback = nullptr;
		bool isOpen = true;
	};
}

#endif