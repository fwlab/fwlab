#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <filamentapp/Config.h>
#include "scene/Scene.h"

class Application {
public:
	explicit Application();
	virtual ~Application();
	void start();
	void stop();
private:
	Config config;
	Scene* scene = nullptr;
};

#endif