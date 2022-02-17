#ifndef UI_SIDEBAR_SIDE_BAR_H
#define UI_SIDEBAR_SIDE_BAR_H
#include "../Component.h"

namespace ui::sidebar
{
    class SideBar : public Component
    {
    public:
        void render() override;

    private:
        float width = 240;
    };
}

#endif