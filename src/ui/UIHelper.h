#ifndef FWLAB_UI_UI_HELPER_H
#define FWLAB_UI_UI_HELPER_H
#include <SDL.h>
#include <filament/View.h>
#include <filagui/ImGuiHelper.h>
#include <utils/Path.h>

namespace ui
{
    class UIHelper
    {
    public:
        UIHelper();
        virtual ~UIHelper();
        filament::View *getView() const noexcept;
        filagui::ImGuiHelper *getImGuiHelper();

    private:
        void handleSDLEvent(SDL_Event *event) const noexcept;
        void handleRender(void *data);
        void handleAfterRender(void *data);
        void handleImguiCommands(filament::Engine *engine, filament::View *view);
        const std::string id = "UIHelper";
        utils::Path fontPath = "assets/fonts/Roboto-Medium.ttf";
        filagui::ImGuiHelper *helper;
        uint64_t mTime;
    };
}

#endif