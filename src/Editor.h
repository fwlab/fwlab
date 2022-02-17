#ifndef FWLAB_EDITOR_H
#define FWLAB_EDITOR_H
#include "ui/Component.h"
#include "ui/menubar/MenuBar.h"
#include "ui/sidebar/SideBar.h"

class Editor final : public ui::Component
{
public:
    Editor();
    virtual ~Editor();
    void render() override;

private:
    ui::menubar::MenuBar *menubar;
    ui::sidebar::SideBar *sidebar;
};

#endif