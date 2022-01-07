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
		material->metallic = 0;
		material->roughness = 0;
		material->create();

		plane = new Mesh();
		plane->receiveShadows = true;
		plane->create(geometry, material);
		plane->setTranslation({ 0, -2, -10 });
		plane->setRotation(-M_PI / 2, { 1, 0, 0 });
		scene->addEntity(plane->entity);
	}

	// box
	{
		BoxGeometry* geometry = new BoxGeometry();
		geometry->create(1, 1, 1);

		LitMaterial* material = new LitMaterial();
		material->baseColor = { 1, 0, 0, 1 };
		material->metallic = 0;
		material->roughness = 0;
		material->create();

		box = new Mesh();
		box->castShadows = true;
		box->receiveShadows = true;
		box->create(geometry, material);
		box->setTranslation({ 0, 0, -10 });
		scene->addEntity(box->entity);
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
	box->setRotation(now, filament::math::double3{ 0, 1, 0 });
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