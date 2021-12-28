#include "../gl/gl.h"
#include "resources/resources.h"
#include "BoxScene.h"

using namespace gl::geometry;
using namespace gl::material;
using namespace gl::object;
using namespace gl::light;

Context context;
Light* light;
Mesh* plane;
Mesh* box;

void BoxScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	context = { &app, engine, view, scene };

	// light
	light = new Light(&context);
	light->create();
	scene->addEntity(light->entity);

	// plane
	{
		PlaneGeometry* geometry = new PlaneGeometry(&context);
		geometry->create(10, 10);

		StandardMaterial* material = new StandardMaterial(&context);
		material->metallic = 0;
		material->roughness = 0;
		material->create();

		plane = new Mesh(&context);
		plane->receiveShadows = true;
		plane->create(geometry, material);
		plane->setTranslation({ 0, -2, -10 });
		plane->setRotation(-M_PI / 2, { 1, 0, 0 });
		scene->addEntity(plane->entity);
	}

	// box
	{
		BoxGeometry* geometry = new BoxGeometry(&context);
		geometry->create(1, 1, 1);

		StandardMaterial* material = new StandardMaterial(&context);
		material->baseColor = { 1, 0, 0, 1 };
		material->metallic = 0;
		material->roughness = 0;
		material->create();

		box = new Mesh(&context);
		box->castShadows = true;
		box->receiveShadows = true;
		box->create(geometry, material);
		box->setTranslation({ 0, 0, -10 });
		scene->addEntity(box->entity);
	}
}

void BoxScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete plane;
	delete box;
	delete light;
}

void BoxScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	box->setRotation(now, filament::math::double3{ 0, 1, 0 });
}
