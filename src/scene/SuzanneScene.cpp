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
	gl::init(engine, view, scene);

	// light
	light = new Light();
	scene->addEntity(light->getEntity());

	// loader
	loader = new FilameshLoader();
	mesh = loader->load(RESOURCES_MONKEY_DATA);
	auto& manager = engine->getRenderableManager();
	auto instance = manager.getInstance(mesh->getEntity());
	manager.setCastShadows(instance, true);
	manager.setReceiveShadows(instance, true);

	mesh->setPosition({ 0, 0, -10 });
	mesh->setScale({ 2, 2, 2 });
	scene->addEntity(mesh->getEntity());
}

void SuzanneScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete mesh;
	delete loader;
	delete light;
}

void SuzanneScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	mesh->setRotation(filament::math::double3{ 0, 1, 0 }, now);
}
