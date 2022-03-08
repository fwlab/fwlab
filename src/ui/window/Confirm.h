#ifndef FWLAB_UI_WINDOW_CONFIRM_H
#define FWLAB_UI_WINDOW_CONFIRM_H
#include <functional>
#include <string>
#include "../Component.h"

namespace fwlab::ui::window
{
	class Confirm : public Component
	{
	public:
		Confirm(std::string content, std::string title = "Ñ¯ÎÊ");
		virtual ~Confirm();
		void render() override;
		void setOKCallback(std::function<void(Confirm* view)> callback);
		void setCancelCallback(std::function<void(Confirm* view)> callback);

	private:
		std::string content;
		std::string title;
		float width = 320;
		float height = 160;
		std::function<void(Confirm* view)> okCallback = nullptr;
		std::function<void(Confirm* view)> cancelCallback = nullptr;
		bool isOpen = true;
		bool isOK = false;
	};
}

#endif