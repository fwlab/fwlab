#include <imgui.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>
#include <utils/EntityManager.h>
#include "HirarchyPanel.h"
#include "../../../context/context.h"

using namespace ui::sidebar::scene;

HirarchyPanel::HirarchyPanel()
{
}

HirarchyPanel::~HirarchyPanel()
{
}

void HirarchyPanel::render()
{
    if (!this->isInit)
    {
        this->createTree(app->getScene());
    }

    if (ImGui::TreeNode("Basic"))
    {
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
        {
            if (ImGui::BeginTabItem("Avocado"))
            {
                ImGui::Text("This is the Avocado tab!\nblah blah blah blah blah");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Broccoli"))
            {
                ImGui::Text("This is the Broccoli tab!\nblah blah blah blah blah");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Cucumber"))
            {
                ImGui::Text("This is the Cucumber tab!\nblah blah blah blah blah");
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::Separator();
        ImGui::TreePop();
    }
}

void HirarchyPanel::createTree(filament::Scene *scene)
{
    this->isInit = true;

    auto &entityManager = app->getEngine()->getEntityManager();

    // auto &manager = app->getEngine()->getTransformManager();

    // manager.getInstance()
}