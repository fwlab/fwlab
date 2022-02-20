#ifndef UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#define UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#include "../../Component.h"

namespace ui::sidebar::scene
{
    class HirarchyPanel : public Component
    {
    public:
        void render() override;

    private:
        float width = 240;
    };
}

#endif