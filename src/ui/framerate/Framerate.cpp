#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
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
		// delete rates;
	}

	void Framerate::render()
	{
		ImVec2 size = ImGui::GetIO().DisplaySize;

		ImGui::SetNextWindowPos(ImVec2(size.x - width, 26));

		ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Once);

		if (ImGui::Begin("Framerate", nullptr,
			ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDecoration))
		{
			char buf[10];
			itoa(std::floor(fps), buf, 10);
			std::strcat(buf, "fps");
			ImGui::PlotLines(buf, rates, 60, current, nullptr, 0, 60);
			ImGui::End();
		}
	}

	void Framerate::handleRender(void* data)
	{
		frameCount++;
		auto time = reinterpret_cast<event::Time*>(data);
		if (time->time - lastTime < 1)
		{
			return;
		}

		double deltaTime = time->time - lastTime;
		lastTime = time->time;
		fps = deltaTime > 0 ? frameCount / deltaTime : 60;
		frameCount = 0;

		rates[current] = fps;
		rates[current + 60] = fps;
		current++;
		if (current >= 60)
		{
			current = 0;
		}
	}
}
