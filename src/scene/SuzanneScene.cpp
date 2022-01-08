#include "../gl/gl.h"
#include "resources/resources.h"
#include "SuzanneScene.h"

using namespace gl::object;
using namespace gl::light;
using namespace gl::loader;

Light* light;
FilameshLoader* loader;
Mesh* mesh;

void SuzanneScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	gl::init(&app, engine, view, scene);

	// light
	light = new Light();
	light->create();
	scene->addEntity(light->entity);

	// loader
	loader = new FilameshLoader();
	mesh = loader->load(RESOURCES_MONKEY_DATA);
	auto& manager = engine->getRenderableManager();
	auto instance = manager.getInstance(mesh->entity);
	manager.setCastShadows(instance, true);
	manager.setReceiveShadows(instance, true);

	mesh->setTranslation({ 0, 0, -10 });
	mesh->setScaling({ 2, 2, 2 });
	scene->addEntity(mesh->entity);
}

void SuzanneScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	delete light;
}

void SuzanneScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	mesh->setRotation(now, filament::math::double3{ 0, 1, 0 });
}
