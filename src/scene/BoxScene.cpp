#include "imgui.h"
#include <viewer/SimpleViewer.h>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "BoxScene.h"

filament::viewer::SimpleViewer* viewer;
gl::PerspectiveCamera* camera;
gl::Light* light;
gl::Mesh* plane;
gl::Mesh* box;

void BoxScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	gl::init(&app, engine, view, scene);

	// camera
	auto& viewport = view->getViewport();
	camera = new gl::PerspectiveCamera(50, float(viewport.width) / viewport.height, 0.1, 2000);
	camera->camera->lookAt({ 2, 2, 2 }, { 0, 0, 0 });
	view->setCamera(camera->camera);

	// light
	light = new gl::Light();
	light->create();
	scene->addEntity(light->entity);

	// viewer
	viewer = new filament::viewer::SimpleViewer(engine, scene, view);

	// plane
	{
		gl::PlaneGeometry* geometry = new gl::PlaneGeometry();
		geometry->create(10, 10);

		gl::LitMaterial* material = new gl::LitMaterial();
		material->metallic = 0;
		material->roughness = 0;

		plane = new gl::Mesh();
		plane->receiveShadows = true;
		plane->create(geometry, material);
		plane->setTranslation({ 0, -2, 0 });
		plane->setRotation(-M_PI / 2, { 1, 0, 0 });
		scene->addEntity(plane->entity);
	}

	// box
	{
		gl::BoxGeometry* geometry = new gl::BoxGeometry();
		geometry->create(1, 1, 1);

		gl::LitMaterial* material = new gl::LitMaterial();
		material->baseColor = { 1, 0, 0, 1 };
		material->metallic = 0;
		material->roughness = 0;

		box = new gl::Mesh();
		box->castShadows = true;
		box->receiveShadows = true;
		box->create(geometry, material);
		box->setTranslation({ 0, 0, 0 });
		scene->addEntity(box->entity);
	}
}

void BoxScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete plane;
	delete box;
	delete light;
	delete viewer;
	delete camera;
}

void BoxScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	box->setRotation(now, filament::math::double3{ 0, 1, 0 });
}

void BoxScene::imgui(filament::Engine* engine, filament::View* view)
{
	viewer->updateUserInterface();
}