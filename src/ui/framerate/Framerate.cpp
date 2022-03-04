#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <imgui.h>
#include "Framerate.h"
#include "../../context/context.h"
#include "../../event/EventList.h"

#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

namespace fwlab::ui::framerate
{
	float Framerate::rates[120] = { 0 };

	Framerate::Framerate()
	{
		app->addEventListener(event::RENDER, id, std::bind(&Framerate::handleRender, this, std::placeholders::_1));
	}

	Framerate::~Framerate()
	{

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

		ImGui::SetNextWindowPos(ImVec2(size.x - 328, 80));
		ImGui::SetNextWindowSize(ImVec2(320, 560), ImGuiCond_Once);

		if (ImGui::Begin("训练"))
		{
			renderPlots();
			ImGui::End();
		}
	}

	void Framerate::renderPlots()
	{
		static bool animate = true;
		ImGui::Checkbox("Animate", &animate);

		static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
		ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));

		// Create a dummy array of contiguous float values to plot
		// Tip: If your float aren't contiguous but part of a structure, you can pass a pointer to your first float
		// and the sizeof() of your structure in the "stride" parameter.
		static float values[90] = {};
		static int values_offset = 0;
		static double refresh_time = 0.0;
		if (!animate || refresh_time == 0.0)
			refresh_time = ImGui::GetTime();
		while (refresh_time < ImGui::GetTime()) // Create dummy data at fixed 60 Hz rate for the demo
		{
			static float phase = 0.0f;
			values[values_offset] = cosf(phase);
			values_offset = (values_offset + 1) % IM_ARRAYSIZE(values);
			phase += 0.10f * values_offset;
			refresh_time += 1.0f / 60.0f;
		}

		// Plots can display overlay texts
		// (in this example, we will display an average value)
		{
			float average = 0.0f;
			for (int n = 0; n < IM_ARRAYSIZE(values); n++)
				average += values[n];
			average /= (float)IM_ARRAYSIZE(values);
			char overlay[32];
			sprintf(overlay, "avg %f", average);
			ImGui::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, overlay, -1.0f, 1.0f, ImVec2(0, 80.0f));
		}
		ImGui::PlotHistogram("Histogram", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));

		// Use functions to generate output
		// FIXME: This is rather awkward because current plot API only pass in indices.
		// We probably want an API passing floats and user provide sample rate/count.
		struct Funcs
		{
			static float Sin(void*, int i) { return sinf(i * 0.1f); }
			static float Saw(void*, int i) { return (i & 1) ? 1.0f : -1.0f; }
		};
		static int func_type = 0, display_count = 70;
		ImGui::Separator();
		ImGui::SetNextItemWidth(100);
		ImGui::Combo("func", &func_type, "Sin\0Saw\0");
		ImGui::SameLine();
		ImGui::SliderInt("Sample count", &display_count, 1, 400);
		float (*func)(void*, int) = (func_type == 0) ? Funcs::Sin : Funcs::Saw;
		ImGui::PlotLines("Lines", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
		ImGui::PlotHistogram("Histogram", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
		ImGui::Separator();

		// Animate a simple progress bar
		static float progress = 0.0f, progress_dir = 1.0f;
		if (animate)
		{
			progress += progress_dir * 0.4f * ImGui::GetIO().DeltaTime;
			if (progress >= +1.1f) { progress = +1.1f; progress_dir *= -1.0f; }
			if (progress <= -0.1f) { progress = -0.1f; progress_dir *= -1.0f; }
		}

		// Typically we would use ImVec2(-1.0f,0.0f) or ImVec2(-FLT_MIN,0.0f) to use all available width,
		// or ImVec2(width,0.0f) for a specified width. ImVec2(0.0f,0.0f) uses ItemWidth.
		ImGui::ProgressBar(progress, ImVec2(0.0f, 0.0f));
		ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
		ImGui::Text("Progress Bar");

		float progress_saturated = IM_CLAMP(progress, 0.0f, 1.0f);
		char buf[32];
		sprintf(buf, "%d/%d", (int)(progress_saturated * 1753), 1753);
		ImGui::ProgressBar(progress, ImVec2(0.f, 0.f), buf);
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
