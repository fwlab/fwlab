#ifndef FWLAB_SCENE_H
#define FWLAB_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>

class Scene {
public:
	Scene();
	virtual ~Scene();
	virtual void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	virtual void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	virtual void animate(filament::Engine* engine, filament::View* view, double now);
	virtual void imgui(filament::Engine* engine, filament::View* view);
};
#endif