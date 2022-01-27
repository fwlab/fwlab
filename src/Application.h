#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <SDL.h>
#include <filament/Camera.h>
#include <filament/Engine.h>
#include <filament/Scene.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Viewport.h>
#include <camutils/Manipulator.h>
#include <utils/Entity.h>
#include "event/EventDispatcher.h"
#include "ui/UIHelper.h"
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
	filament::Engine::Backend getBackend() const noexcept;
	filament::SwapChain *getSwapChain() const noexcept;
	filament::Renderer *getRenderer() const noexcept;
	utils::Entity getCameraEntity() const noexcept;
	filament::Camera *getCamera() const noexcept;
	filament::View *getView() const noexcept;
	filament::Viewport *getViewport() const noexcept;
	filament::Scene *getScene() const noexcept;
	event::EventDispatcher *getEventDispatcher() const noexcept;
	ui::UIHelper *getUIHelper() const noexcept;
	void addEventListener(const std::string eventName, std::string id, std::function<void(void *)> listener) noexcept;
	void removeEventListener(const std::string eventName, std::string id) noexcept;
	bool hasEventListener(const std::string eventName, std::string id) const noexcept;
	void dispatchEvent(const std::string eventName, void *params = nullptr) const noexcept;

protected:
	void clean() noexcept;
	SDL_Window *window = nullptr;
	bool isRunning = false;
	event::EventDispatcher *event = nullptr;
	ui::UIHelper *ui = nullptr;

	filament::Engine *engine = nullptr;
	filament::SwapChain *swapChain = nullptr;
	filament::Renderer *renderer = nullptr;

	utils::Entity cameraEntity;
	filament::Camera *camera = nullptr;
	filament::View *view = nullptr;
	filament::Viewport *viewport = nullptr;
	filament::camutils::Manipulator<float> *controller;
	filament::Scene *scene = nullptr;

	Scene *myScene = nullptr;
};

#endif