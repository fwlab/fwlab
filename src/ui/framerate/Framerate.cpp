#include <algorithm>
#include <imgui.h>
#include "Framerate.h"
#include "../../context/context.h"
#include "../../event/EventList.h"

namespace fwlab::ui::framerate
{
	Framerate::Framerate()
	{
		rates = new float[120]();
		app->addEventListener(event::RENDER, id, std::bind(&Framerate::handleRender, this, std::placeholders::_1));
	}

	Framerate::~Framerate()
	{
		delete rates;
	}

	void Framerate::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		ImGui::SetNextWindowPos(ImVec2(size.x - width, 26));

		ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Once);

		if (ImGui::Begin("Framerate", nullptr,
			ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDecoration))
		{
			ImGui::PlotLines("60fps", rates, 60, 0);
			ImGui::End();
		}
	}

	void Framerate::handleRender(void* data)
	{
		auto time = reinterpret_cast<event::Time*>(data);
		rates[0] = 1 / time->deltaTime;
	}
}