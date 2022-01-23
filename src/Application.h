#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <SDL.h>
#include <filamentapp/Config.h>
#include "scene/Scene.h"

class Application
{
public:
	explicit Application();
	virtual ~Application();
	void start();
	void stop();

private:
	Config config;
	SDL_Window *window;
	Scene *scene = nullptr;
};

#endif