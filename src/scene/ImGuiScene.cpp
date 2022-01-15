#include <imgui.h>
#include <viewer/SimpleViewer.h>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "ImGuiScene.h"

using namespace gl::geometry;
using namespace gl::material;
using namespace gl::object;
using namespace gl::light;

Light* light;
Mesh* plane;
Mesh* box;
filament::viewer::SimpleViewer* viewer;

void ImGuiScene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	FilamentApp& app = FilamentApp::get();
	gl::init(&app, engine, view, scene);

	// light
	light = new Light();
	light->create();
	scene->addEntity(light->entity);

	// plane
	{
		PlaneGeometry* geometry = new PlaneGeometry();
		geometry->create(10, 10);

		LitMaterial* material = new LitMaterial();
		material->setMetallic(0);
		material->setRoughness(0);

		plane = new Mesh(geometry, material);
		plane->setReceiveShadows(true);
		plane->setPosition({ 0, -2, -10 });
		plane->setRotation({ 1, 0, 0 }, -M_PI / 2);
		scene->addEntity(plane->getEntity());
	}

	// box
	{
		BoxGeometry* geometry = new BoxGeometry();
		geometry->create(1, 1, 1);

		LitMaterial* material = new LitMaterial();
		material->setBaseColor({ 1, 0, 0, 1 });
		material->setMetallic(0);
		material->setRoughness(0);

		box = new Mesh(geometry, material);
		box->setCastShadows(true);
		box->setReceiveShadows(true);
		box->setPosition({ 0, 0, -10 });
		scene->addEntity(box->getEntity());
	}

	// UI
	viewer = new filament::viewer::SimpleViewer(engine, scene, view);
	viewer->setUiCallback([&]() {
		this->uiCallback();
		});
}

void ImGuiScene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	delete plane;
	delete box;
	delete light;
	delete viewer;
}

void ImGuiScene::animate(filament::Engine* engine, filament::View* view, double now)
{
	box->setRotation(filament::math::double3{ 0, 1, 0 }, now);
}

void ImGuiScene::imgui(filament::Engine* engine, filament::View* view)
{
	viewer->updateUserInterface();
	FilamentApp::get().setSidebarWidth(viewer->getSidebarWidth());
}

void ImGuiScene::uiCallback()
{
	ImGui::Text("Hello, world!");
}