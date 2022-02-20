#include <imgui.h>
#include "ScenePanel.h"

using namespace ui::sidebar::scene;

ScenePanel::ScenePanel()
{
    hirarchyPanel = new HirarchyPanel();
    historyPanel = new HistoryPanel();
}

ScenePanel::~ScenePanel()
{
    delete hirarchyPanel;
    delete historyPanel;
}

void ScenePanel::render()
{
    ImGuiTabBarFlags flags = ImGuiTabBarFlags_None;
    if (ImGui::BeginTabBar("scene-tab", flags))
    {
        if (ImGui::BeginTabItem("场景", &isSceneTabShow))
        {
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("历史", &isHistoryTabShow))
        {
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    if (isSceneTabShow)
    {
        hirarchyPanel->render();
    }

    if (isHistoryTabShow)
    {
        historyPanel->render();
    }
}