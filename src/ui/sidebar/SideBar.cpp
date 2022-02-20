#include <imgui.h>
#include "SideBar.h"

using namespace ui::sidebar;

SideBar::SideBar()
{
    hirarchy = new scene::HirarchyPanel();
}

SideBar::~SideBar()
{
    delete hirarchy;
}

void SideBar::render()
{
    float top = 26;

    // Disable rounding and draw a fixed-height ImGui window that looks like a sidebar.
    ImGui::GetStyle().WindowRounding = 0;
    ImGui::SetNextWindowPos(ImVec2(0, top));

    ImVec2 size = ImGui::GetIO().DisplaySize;

    ImGui::SetNextWindowSize(ImVec2(size.x, size.y - top), ImGuiCond_Once);
    ImGui::SetNextWindowSizeConstraints(ImVec2(20, size.y - top), ImVec2(width, size.y - top));

    if (ImGui::Begin("SideBar", nullptr, ImGuiWindowFlags_NoTitleBar))
    {
        ImGui::End();
    }
}