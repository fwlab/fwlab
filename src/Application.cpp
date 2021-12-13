#include <Windows.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "utils/EncodingUtils.h"
#include "scene/Scene.h"
#include "Application.h"

Application::Application()
{
	config.title = EncodingUtils::GBKToUTF8("�˹�����ʵ����");
}

Application::~Application()
{
}

void Application::start()
{
	FilamentApp::get().animate(Scene::animate);
	FilamentApp::get().run(config, Scene::setup, Scene::cleanup);
}

void Application::stop()
{
}