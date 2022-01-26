#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <SDL.h>
#include <filament/Camera.h>
#include <filament/Engine.h>
#include <filament/Scene.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Viewport.h>
#include <utils/Entity.h>
#include "event/EventDispatcher.h"
#include "scene/Scene.h"

class Application
{
public:
	Application() = default;
	virtual ~Application() = default;
	void start();
	void stop();
	SDL_Window *getSDLWindow() const noexcept;
	filament::Engine *getEngine() const noexcept;
	filament::SwapChain *getSwapChain() const noexcept;
	filament::Renderer *getRenderer() const noexcept;
	utils::Entity getCameraEntity() const noexcept;
	filament::Camera *getCamera() const noexcept;
	filament::View *getView() const noexcept;
	filament::Viewport *getViewport() const noexcept;
	filament::Scene *getScene() const noexcept;

protected:
	void clean() noexcept;
	SDL_Window *window = nullptr;
	bool isRunning = false;
	event::EventDispatcher *event = nullptr;

	filament::Engine *engine = nullptr;
	filament::SwapChain *swapChain = nullptr;
	filament::Renderer *renderer = nullptr;

	utils::Entity cameraEntity;
	filament::Camera *camera = nullptr;
	filament::View *view = nullptr;
	filament::Viewport *viewport = nullptr;
	filament::Scene *scene = nullptr;

	Scene *myScene = nullptr;
};

#endif