#ifndef FWLAB_CONTEXT_H
#define FWLAB_CONTEXT_H
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>

/// <summary>
/// 上下文环境
/// </summary>
struct Context {
	filament::Engine* engine;
	filament::View* view;
	filament::Scene* scene;
};

#endif