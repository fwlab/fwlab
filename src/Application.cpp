#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <utils/EntityManager.h>
#include "utils/SDLUtils.h"
#include "gl/gl.h"
#include "scene/BoxScene.h"
#include "Application.h"
#include "context/context.h"
#include "event/EventList.h"

namespace fwlab
{
	Application::Application()
	{
		if (SDL_Init(SDL_INIT_EVENTS) > 0)
		{
			std::cerr << "failed to init SDL." << std::endl;
			return;
		}
		::app = this;

		clock = new utils::Clock(false);
		time = new event::Time;
	}

	Application::~Application()
	{
		SDL_Quit();

		delete clock;
		delete time;
	}

	void Application::start()
	{
		event = new EventDispatcher();
		event->start();
		event->dispatchEvent(event::BEFORE_APP_START);

		uint32_t flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE;
		int width = 1000;
		int height = 600;
		window = SDL_CreateWindow("人工智能实验室", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		engine = filament::Engine::create();
		swapChain = engine->createSwapChain(utils::SDLUtils::getNativeWindow(window));
		renderer = engine->createRenderer();

		cameraEntity = utils::EntityManager::get().create();
		camera = engine->createCamera(cameraEntity);
		camera->setProjection(60, float(width) / height, 0.1, 2000, filament::Camera::Fov::VERTICAL);
		camera->setExposure(16.0f, 1 / 125.0f, 100.0f);
		camera->lookAt({ 3, 4, 5 }, { 0, 0, 0 });

		view = engine->createView();
		viewport = new filament::Viewport(0, 0, width, height);
		view->setViewport(*viewport);
		view->setCamera(camera);

		controller = new controller::OrbitController();

		scene = engine->createScene();
		view->setScene(scene);

		gl::init(engine, view, scene);
		myScene = new BoxScene();
		myScene->setup(engine, view, scene);

		isRunning = true;

		clock->start();

		event->dispatchEvent(event::APP_STARTED);

		ui = new ui::UIHelper();
		editor = new Editor();
		ui->setCallback([&]()
			{ editor->render(); });

		while (isRunning)
		{
			time->time = clock->getElapsedTime();
			time->deltaTime = clock->getDelta();

			event->pollEvent();

			event->dispatchEvent(event::BEFORE_RENDER, time);

			if (renderer->beginFrame(swapChain))
			{
				renderer->render(view);
				event->dispatchEvent(event::RENDER, time);
				renderer->endFrame();
			}

			myScene->animate(engine, view, time->time);

			event->dispatchEvent(event::ANIMATE, time);

			clock->update();

			// 保持帧率稳定在60fps
			int sleepTime = 1000.0 / 60 - clock->getDelta() * 1000;
			if (sleepTime > 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
			}
		}
	}

	void Application::stop()
	{
		isRunning = false;
	}

	void Application::clean() noexcept
	{
		event->dispatchEvent(event::BEFORE_APP_STOP);

		myScene->cleanup(engine, view, scene);
		delete myScene;

		engine->destroyCameraComponent(cameraEntity);
		engine->destroy(scene);
		engine->destroy(view);
		engine->destroy(renderer);
		engine->destroy(swapChain);
		filament::Engine::destroy(engine);
		delete viewport;

		delete editor;
		delete ui;
		delete controller;

		event->dispatchEvent(event::APP_STOPPED);
		delete event;

		::app = nullptr;

		SDL_DestroyWindow(window);
	}

	bool Application::getIsRunning() const noexcept
	{
		return isRunning;
	}

	utils::Clock* Application::getClock() const noexcept
	{
		return clock;
	}

	event::Time* Application::getTime() const noexcept
	{
		return time;
	}

	EventDispatcher* Application::getEventDispatcher() const noexcept
	{
		return event;
	}

	ui::UIHelper* Application::getUIHelper() const noexcept
	{
		return ui;
	}

	SDL_Window* Application::getSDLWindow() const noexcept
	{
		return window;
	}

	filament::Engine* Application::getEngine() const noexcept
	{
		return engine;
	}

	filament::Engine::Backend Application::getBackend() const noexcept
	{
		return engine->getBackend();
	}

	filament::SwapChain* Application::getSwapChain() const noexcept
	{
		return swapChain;
	}

	filament::Renderer* Application::getRenderer() const noexcept
	{
		return renderer;
	}

	utils::Entity Application::getCameraEntity() const noexcept
	{
		return cameraEntity;
	}

	filament::Camera* Application::getCamera() const noexcept
	{
		return camera;
	}

	filament::View* Application::getView() const noexcept
	{
		return view;
	}

	filament::Viewport* Application::getViewport() const noexcept
	{
		return viewport;
	}

	filament::Scene* Application::getScene() const noexcept
	{
		return scene;
	}

	controller::OrbitController* Application::getController() const noexcept
	{
		return controller;
	}

	void Application::addEventListener(const std::string eventName, std::string id, std::function<void(void*)> listener) noexcept
	{
		event->addEventListener(eventName, id, listener);
	}

	void Application::removeEventListener(const std::string eventName, std::string id) noexcept
	{
		event->removeEventListener(eventName, id);
	}

	bool Application::hasEventListener(const std::string eventName, std::string id) const noexcept
	{
		return event->hasEventListener(eventName, id);
	}

	void Application::dispatchEvent(const std::string eventName, void* params) const noexcept
	{
		event->dispatchEvent(eventName, params);
	}
}