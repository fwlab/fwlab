#ifndef FWLAB_SCENE_H
#define FWLAB_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>

/// <summary>
/// ³¡¾°
/// </summary>
class Scene {
public:
	static void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	static void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	static void animate(filament::Engine* engine, filament::View* view, double now);
	static void imgui(filament::Engine* engine, filament::View* view);
	static void uiCallback();

private:
	Scene() {}
};
#endif // !FWLAB_SCENE_H