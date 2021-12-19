#include <Windows.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "utils/EncodingUtils.h"
#include "scene/Scene.h"
#include "Application.h"

static const char* IBL_FOLDER = "assets/ibl/lightroom_14b";

Application::Application()
{
	config.title = EncodingUtils::GBKToUTF8("人工智能实验室");
	config.iblDirectory = FilamentApp::getRootAssetsPath() + IBL_FOLDER;
}

Application::~Application()
{
}

void Application::start()
{
	FilamentApp::get().animate(Scene::animate);
	FilamentApp::get().run(config, Scene::setup, Scene::cleanup, Scene::imgui);
}

void Application::stop()
{
}