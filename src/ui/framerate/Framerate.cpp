#include <imgui.h>
#include "Framerate.h"

using namespace ui::framerate;

void Framerate::render()
{
	static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
	if (ImGui::Begin("Frame"))
	{
		ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));
		ImGui::End();
	}
}