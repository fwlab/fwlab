#ifndef UI_SIDEBAR_SIDE_BAR_H
#define UI_SIDEBAR_SIDE_BAR_H
#include "../Component.h"
#include "scene/ScenePanel.h"

namespace ui::sidebar
{
    class SideBar : public Component
    {
    public:
        SideBar();
        virtual ~SideBar();
        void render() override;

    private:
        float width = 240;
        scene::ScenePanel *scenePanel = nullptr;
    };
}

#endif