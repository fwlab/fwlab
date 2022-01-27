#ifndef FWLAB_UI_UI_HELPER_H
#define FWLAB_UI_UI_HELPER_H
#include <SDL.h>
#include <filagui/ImGuiHelper.h>
#include <utils/Path.h>

namespace ui
{
    class UIHelper
    {
    public:
        UIHelper();
        virtual ~UIHelper();

    private:
        void handleSDLEvent(SDL_Event *event) const noexcept;
        void handleRender();
        const std::string id = "UIHelper";
        utils::Path fontPath = "assets/fonts/Roboto-Medium.ttf";
        filagui::ImGuiHelper *helper;
    };
}

#endif