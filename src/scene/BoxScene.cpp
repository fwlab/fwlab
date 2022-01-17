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
gl::TextureLoader* loader;

void BoxScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	gl::init(&app, engine, view, scene);

	// camera
	auto& viewport = view->getViewport();
	camera = new gl::PerspectiveCamera(50, float(viewport.width) / viewport.height, 0.1, 2000);
	camera->lookAt({ 2, 2, 2 }, { 0, 0, 0 });
	camera->setScaling({ 2, 2 });
	view->setCamera(camera->getCamera());

	// light
	light = new gl::Light();
	scene->addEntity(light->getEntity());

	// viewer
	viewer = new filament::viewer::SimpleViewer(engine, scene, view);

	// loader
	loader = new gl::TextureLoader();
	auto texture = loader->load("assets/images/girl.png", filament::Texture::Format::RGBA);

	// material
	auto material = new gl::ClothMaterial();
	material->setMap(texture);

	// plane
	{
		gl::PlaneGeometry* geometry = new gl::PlaneGeometry();
		geometry->create(10, 10);

		plane = new gl::Mesh(geometry, material);
		plane->setReceiveShadows(true);
		plane->setPosition({ 0, -2, 0 });
		plane->setRotation({ 1, 0, 0 }, -M_PI / 2);
		scene->addEntity(plane->getEntity());
	}

	// box
	{
		gl::BoxGeometry* geometry = new gl::BoxGeometry();
		geometry->create(1, 1, 1);

		box = new gl::Mesh(geometry, material);
		box->setCastShadows(true);
		box->setReceiveShadows(true);
		box->setPosition({ 0, 0, 0 });
		scene->addEntity(box->getEntity());
	}
}

void BoxScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete plane;
	delete box;
	delete light;
	delete viewer;
	delete camera;
	delete loader;
}

void BoxScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	box->setRotation(filament::math::double3{ 0, 1, 0 }, now);
}

void BoxScene::imgui(filament::Engine* engine, filament::View* view)
{
	viewer->updateUserInterface();
}