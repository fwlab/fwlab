#include <functional>
#include <filament/Engine.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "utils/EncodingUtils.h"
#include "scene/AnimationScene.h"
#include "Application.h"

static const char* IBL_FOLDER = "assets/ibl/lightroom_14b";

Application::Application()
{
	config.title = EncodingUtils::GBKToUTF8("人工智能实验室");
	// config.iblDirectory = FilamentApp::getRootAssetsPath() + IBL_FOLDER;
	scene = new AnimationScene();
}

Application::~Application()
{
	delete scene;
}

void Application::start()
{
	auto setup = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene) {
		this->scene->setup(engine, view, scene);
	};
	auto cleanup = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene) {
		this->scene->cleanup(engine, view, scene);
	};
	auto animate = [&](filament::Engine* engine, filament::View* view, double now) {
		this->scene->animate(engine, view, now);
	};
	auto imgui = [&](filament::Engine* engine, filament::View* view) {
		this->scene->imgui(engine, view);
	};
	auto preRender = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) {
		this->scene->preRender(engine, view, scene, renderer);
	};

	auto postRender = [&](filament::Engine* engine, filament::View* view, filament::Scene* scene, filament::Renderer* renderer) {
		this->scene->postRender(engine, view, scene, renderer);
	};

	auto resize = [&](filament::Engine* engine, filament::View* view) {
		this->scene->resize(engine, view);
	};

	auto& app = FilamentApp::get();
	app.animate(animate);
	app.resize(resize);
	app.run(config, setup, cleanup, imgui, preRender, postRender);
}

void Application::stop()
{

}