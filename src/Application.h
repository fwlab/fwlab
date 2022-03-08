#ifndef FWLAB_APPLICATION_H
#define FWLAB_APPLICATION_H
#include <functional>
#include <string>
#include <SDL.h>
#include <filament/Camera.h>
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/Scene.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Viewport.h>
#include <utils/Entity.h>
#include "utils/Clock.h"
#include "EventDispatcher.h"
#include "Editor.h"
#include "controller/OrbitController.h"
#include "utils/Logger.h"
#include "scene/Scene.h"

namespace fwlab
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void start();
		void stop();
		void info(std::string content, std::string title = "消息");
		void success(std::string content, std::string title = "成功");
		void warn(std::string content, std::string title = "警告");
		void error(std::string content, std::string title = "错误");
		void confirm(std::string content, std::function<void(bool)> callback, std::string title = "询问");
		void prompt(std::string name, std::function<void(std::string)> callback, std::string value = "", std::string title = "请输入");

		bool getIsRunning() const;
		utils::Clock* getClock() const;
		event::Time* getTime() const;
		EventDispatcher* getEventDispatcher() const;

		SDL_Window* getSDLWindow() const;

		filament::Engine* getEngine() const;
		filament::Engine::Backend getBackend() const;
		filament::SwapChain* getSwapChain() const;
		filament::Renderer* getRenderer() const;

		::utils::Entity getCameraEntity() const;
		filament::Camera* getCamera() const;
		filament::View* getView() const;
		filament::Viewport* getViewport() const;
		filament::Scene* getScene() const;

		controller::OrbitController* getController() const;

		void addEventListener(const std::string eventName, std::string id, std::function<void(void*)> listener);
		void removeEventListener(const std::string eventName, std::string id);
		bool hasEventListener(const std::string eventName, std::string id) const;
		void dispatchEvent(const std::string eventName, void* params = nullptr) const;

	protected:
		void clean();
		bool isRunning = false;
		utils::Clock* clock = nullptr;
		event::Time* time = nullptr;
		EventDispatcher* event = nullptr;
		Editor* editor = nullptr;
		utils::Logger* logger = nullptr;

		SDL_Window* window = nullptr;

		filament::Engine* engine = nullptr;
		filament::SwapChain* swapChain = nullptr;
		filament::Renderer* renderer = nullptr;

		::utils::Entity cameraEntity;
		filament::Camera* camera = nullptr;
		filament::View* view = nullptr;
		filament::Viewport* viewport = nullptr;
		filament::Scene* scene = nullptr;

		controller::OrbitController* controller = nullptr;

		scene::Scene* myScene = nullptr;
	};
}

#endif