#ifndef GL_CONTEXT_CONTEXT_H
#define GL_CONTEXT_CONTEXT_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/FilamentApp.h>

namespace gl::context
{
	extern FilamentApp* app;
	extern filament::Engine* engine;
	extern filament::View* view;
	extern filament::Scene* scene;
}

#endif