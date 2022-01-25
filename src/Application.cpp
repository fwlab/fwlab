#include <functional>
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Viewport.h>
#include <utils/EntityManager.h>
#include "utils/SDLUtils.h"
#include "gl/gl.h"
#include "scene/BoxScene.h"
#include "Application.h"

Application::Application()
{
	SDL_Init(SDL_INIT_EVENTS);
	// scene = new BoxScene();
}

Application::~Application()
{
	delete myScene;
}

void Application::start()
{
	uint32_t flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE;
	int width = 1000;
	int height = 600;
	window = SDL_CreateWindow("人工智能实验室", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

	engine = filament::Engine::create();
	swapChain = engine->createSwapChain(utils::SDLUtils::getNativeWindow(window));
	renderer = engine->createRenderer();

	utils::Entity cameraEntity = utils::EntityManager::get().create();
	camera = engine->createCamera(cameraEntity);
	camera->setProjection(60, float(width) / height, 0.1, 2000, filament::Camera::Fov::VERTICAL);
	camera->lookAt({5, 10, 15}, {0, 0, 0});

	view = engine->createView();
	auto viewport = new filament::Viewport(0, 0, 1000, 600);
	view->setViewport(*viewport);
	view->setCamera(camera);

	scene = engine->createScene();
	view->setScene(scene);

	gl::init(engine, view, scene);
	myScene = new BoxScene();
	myScene->setup(engine, view, scene);

	this->isRunning = true;

	SDL_Event event;

	while (this->isRunning)
	{
		if (SDL_PollEvent(&event) == 0)
		{
			continue;
		}
		switch (event.type)
		{
		case SDL_QUIT:
			this->isRunning = false;
			break;
		}

		if (renderer->beginFrame(swapChain))
		{
			renderer->render(view);
			renderer->endFrame();
		}

		myScene->animate(engine, view, renderer->getUserTime());
	}

	myScene->cleanup(engine, view, scene);
}

void Application::stop()
{
	SDL_Quit();
}