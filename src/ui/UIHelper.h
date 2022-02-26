#ifndef FWLAB_UI_UI_HELPER_H
#define FWLAB_UI_UI_HELPER_H
#include <functional>
#include <SDL.h>
#include <filament/View.h>
#include <filagui/ImGuiHelper.h>
#include <utils/Path.h>

namespace fwlab::ui
{
	class UIHelper
	{
	public:
		UIHelper();
		virtual ~UIHelper();
		filament::View* getView() const noexcept;
		filagui::ImGuiHelper* getImGuiHelper();
		std::function<void()> getCallback();
		void setCallback(std::function<void()> callback);

	private:
		void handleSDLEvent(SDL_Event* event) const noexcept;
		void handleRender(void* data);
		void handleSizeChanged(void* data);
		const std::string id = "UIHelper";
		filament::View* view;
		utils::Path fontPath = "assets/fonts/Alibaba-PuHuiTi-Bold.ttf";
		filagui::ImGuiHelper* helper;
		std::function<void()> callback = nullptr;
	};
}

#endif