#ifndef FWLAB_IMGUI_SCENE_H
#define FWLAB_IMGUI_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include "Scene.h"

class ImGuiScene : public Scene {
public:
	void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void animate(filament::Engine* engine, filament::View* view, double now) override;
	void imgui(filament::Engine* engine, filament::View* view) override;

private:
	void uiCallback();
};
#endif