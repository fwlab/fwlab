#ifndef GL_CONTEXT_H
#define GL_CONTEXT_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/FilamentApp.h>

struct Context {
	FilamentApp* app;
	filament::Engine* engine;
	filament::View* view;
	filament::Scene* scene;
};

#endif