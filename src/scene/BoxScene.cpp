#include "imgui.h"
#include <filament/Viewport.h>
#include <viewer/SimpleViewer.h>
#include "../gl/gl.h"
#include "resources/resources.h"
#include "BoxScene.h"
#include "../object/sky/SkyBox.h"

object::sky::Skybox *skybox;
gl::Light *light;
gl::Mesh *plane;
gl::Mesh *box;
gl::TextureLoader *loader;

void BoxScene::setup(filament::Engine *engine, filament::View *view, filament::Scene *scene)
{
	// skybox
	skybox = new object::sky::Skybox();
	scene->setSkybox(skybox->getSkybox());

	// light
	light = new gl::Light();
	scene->addEntity(light->getEntity());

	// loader
	loader = new gl::TextureLoader();
	auto texture = loader->load("assets/images/girl.png", filament::Texture::Format::RGBA);

	// material
	auto material = new gl::ClothMaterial();
	material->setMap(texture);

	// plane
	{
		gl::PlaneGeometry *geometry = new gl::PlaneGeometry();
		geometry->create(10, 10);

		plane = new gl::Mesh(geometry, material);
		plane->setReceiveShadows(true);
		plane->setPosition({0, -2, 0});
		plane->setRotation({1, 0, 0}, -M_PI / 2);
		scene->addEntity(plane->getEntity());
	}

	// box
	{
		gl::BoxGeometry *geometry = new gl::BoxGeometry();
		geometry->create(1, 1, 1);

		box = new gl::Mesh(geometry, material);
		box->setCastShadows(true);
		box->setReceiveShadows(true);
		box->setPosition({0, 0, 0});
		scene->addEntity(box->getEntity());
	}
}

void BoxScene::cleanup(filament::Engine *engine, filament::View *view, filament::Scene *scene)
{
	delete plane;
	delete box;
	delete light;
	delete loader;
	delete skybox;
}

void BoxScene::animate(filament::Engine *engine, filament::View *view, double now)
{
	box->setRotation(filament::math::double3{0, 1, 0}, now);
}

void BoxScene::imgui(filament::Engine *engine, filament::View *view)
{
	ImGui::Begin("Hello", nullptr, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File", true))
		{
			ImGui::MenuItem("New", nullptr, false, true);
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}

	ImGui::End();
}