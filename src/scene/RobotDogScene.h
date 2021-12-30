#ifndef FWLAB_ROBOT_DOG_SCENE_H
#define FWLAB_ROBOT_DOG_SCENE_H
#include <filament/Box.h>
#include <math/mat4.h>
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include "Scene.h"

class RobotDogScene : public Scene {
public:
	void setup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene) override;
	void animate(filament::Engine* engine, filament::View* view, double now) override;
	void imgui(filament::Engine* engine, filament::View* view) override;
	void preRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) override;
	void postRender(filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) override;

private:
	void uiCallback();
	filament::math::mat4f fitIntoUnitCube(const filament::Aabb& bounds, float zoffset);
};
#endif