#include <functional>
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "utils/EncodingUtils.h"
#include "scene/BoxScene.h"
#include "Application.h"

static const char* IBL_FOLDER = "assets/ibl/lightroom_14b";

Application::Application()
{
	config.title = EncodingUtils::GBKToUTF8("人工智能实验室");
	config.iblDirectory = FilamentApp::getRootAssetsPath() + IBL_FOLDER;
	scene = new BoxScene();
}

Application::~Application()
{
	delete scene;
}

void Application::start()
{
	auto _scene = this->scene;

	auto setup = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene) {
		_scene->setup(engine, view, scene);
	};
	auto cleanup = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene) {
		_scene->cleanup(engine, view, scene);
	};
	auto animate = [&](filament::Engine* engine, filament::View* view, double now) {
		_scene->animate(engine, view, now);
	};
	auto imgui = [&](filament::Engine* engine, filament::View* view) {
		_scene->imgui(engine, view);
	};

	FilamentApp::get().animate(animate);
	FilamentApp::get().run(config, setup, cleanup, imgui);
}

void Application::stop()
{

}