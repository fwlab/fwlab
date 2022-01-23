#include <functional>
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "utils/SDLUtils.h"
#include "scene/BoxScene.h"
#include "Application.h"

static const char *IBL_FOLDER = "assets/ibl/lightroom_14b";

Application::Application()
{
	SDL_Init(SDL_INIT_EVENTS);

	const int x = SDL_WINDOWPOS_CENTERED;
	const int y = SDL_WINDOWPOS_CENTERED;
	uint32_t windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE;

	window = SDL_CreateWindow("人工智能实验室", x, y, 1000, 600, windowFlags);

	void *nativeWindow = utils::SDLUtils::getNativeWindow(window);

	// Create the Engine after the window in case this happens to be a single-threaded platform.
	// For single-threaded platforms, we need to ensure that Filament's OpenGL context is
	// current, rather than the one created by SDL.
	//mFilamentApp->mEngine = Engine::create(config.backend);

	config.title = "人工智能实验室";
	config.iblDirectory = FilamentApp::getRootAssetsPath() + IBL_FOLDER;
	scene = new BoxScene();
}

Application::~Application()
{
	SDL_Quit();
	delete scene;
}

void Application::start()
{
	return;
	auto setup = [&](filament::Engine *engine, filament::View *view, filament::Scene *scene)
	{
		this->scene->setup(engine, view, scene);
	};
	auto cleanup = [&](filament::Engine *engine, filament::View *view, filament::Scene *scene)
	{
		this->scene->cleanup(engine, view, scene);
	};
	auto animate = [&](filament::Engine *engine, filament::View *view, double now)
	{
		this->scene->animate(engine, view, now);
	};
	auto imgui = [&](filament::Engine *engine, filament::View *view)
	{
		this->scene->imgui(engine, view);
	};
	auto preRender = [&](filament::Engine *engine, filament::View *view, filament::Scene *scene, filament::Renderer *renderer)
	{
		this->scene->preRender(engine, view, scene, renderer);
	};

	auto postRender = [&](filament::Engine *engine, filament::View *view, filament::Scene *scene, filament::Renderer *renderer)
	{
		this->scene->postRender(engine, view, scene, renderer);
	};

	auto resize = [&](filament::Engine *engine, filament::View *view)
	{
		this->scene->resize(engine, view);
	};

	auto &app = FilamentApp::get();
	app.animate(animate);
	app.resize(resize);
	//app.run(config, (FilamentApp::SetupCallback)setup, (FilamentApp::CleanupCallback)cleanup);
}

void Application::stop()
{
}