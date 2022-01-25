#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <SDL.h>
#include <filament/Camera.h>
#include <filament/Engine.h>
#include <filament/Scene.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include "scene/Scene.h"

class Application
{
public:
	explicit Application();
	virtual ~Application();
	void start();
	void stop();

private:
	SDL_Window *window = nullptr;
	bool isRunning = false;

	filament::Engine *engine = nullptr;
	filament::SwapChain *swapChain = nullptr;
	filament::Renderer *renderer = nullptr;

	filament::Camera *camera = nullptr;
	filament::View *view = nullptr;
	filament::Scene *scene = nullptr;

	Scene *myScene = nullptr;
};

#endif