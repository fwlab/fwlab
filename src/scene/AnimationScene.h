#ifndef ANIMATION_SCENE_H
#define ANIMATION_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include "Scene.h"

class AnimationScene : public Scene {
public:
	void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void animate(filament::Engine* engine, filament::View* view, double now) override;
};
#endif