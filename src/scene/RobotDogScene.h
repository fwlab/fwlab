#ifndef FWLAB_ROBOT_DOG_SCENE_H
#define FWLAB_ROBOT_DOG_SCENE_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include "Scene.h"

class RobotDogScene : public Scene {
public:
	void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void animate(filament::Engine* engine, filament::View* view, double now) override;
	void preRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) override;
	void postRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) override;
};
#endif