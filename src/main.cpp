#include <Windows.h>
#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>
#include "scene/scene.h"
#include "utils/encoding_utils.h"

int WINAPI WinMain(
	_In_  HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	Config config;
	config.title = EncodingUtils::GBKToUTF8("人工智能实验室");
	FilamentApp::get().run(config, Scene::setup, Scene::cleanup);

	return 0;
}
