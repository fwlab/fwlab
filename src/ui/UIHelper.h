#ifndef FWLAB_UI_UI_HELPER_H
#define FWLAB_UI_UI_HELPER_H
#include <filagui/ImGuiHelper.h>

namespace ui
{
    class UIHelper
    {
    public:
        UIHelper();
        virtual ~UIHelper();

    private:
        filagui::ImGuiHelper *helper;
    };
}

#endif