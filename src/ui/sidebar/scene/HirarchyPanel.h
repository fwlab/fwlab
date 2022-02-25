#ifndef UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#define UI_SIDEBAR_SCENE_HIRARCHY_PANEL_H
#include <string>
#include <vector>
#include <filament/Scene.h>
#include "../../Component.h"

namespace ui::sidebar::scene
{
    struct TreeNode
    {
        std::string text;
        std::vector<TreeNode *> children;
    };

    class HirarchyPanel : public Component
    {
    public:
        HirarchyPanel();
        virtual ~HirarchyPanel();
        void render() override;

    private:
        void createTree(filament::Scene *scene);
        bool isInit = false;
        TreeNode *tree = nullptr;
    };
}

#endif