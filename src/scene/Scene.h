#ifndef FWLAB_SCENE_H
#define FWLAB_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Renderer.h>

class Scene {
public:
	Scene();
	virtual ~Scene();
	virtual void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	virtual void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene);
	virtual void animate(filament::Engine* engine, filament::View* view, double now);
	virtual void imgui(filament::Engine* engine, filament::View* view);
	virtual void preRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer);
	virtual void postRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer);
};
#endif