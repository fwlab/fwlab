#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <Windows.h>

#include <filament/Camera.h>
#include <filament/Engine.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include <filament/Scene.h>
#include <filament/Skybox.h>
#include <filament/TransformManager.h>
#include <filament/VertexBuffer.h>
#include <filament/View.h>

#include <utils/EntityManager.h>

#include <filamentapp/Config.h>
#include <filamentapp/FilamentApp.h>

#include "generated/resources/resources.h"

using namespace filament;
using utils::Entity;
using utils::EntityManager;

void setup(Engine*, View*, Scene*);
void cleanup(Engine*, View*, Scene*);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Config config;
	config.title = "My Triangle";

	FilamentApp::get().run(config, setup, cleanup);

	return 0;
}

struct Vertex {
	filament::math::float2 position;
	uint32_t color;
};

static const Vertex TRIANGLE_VERTICES[3] = {
	{{1, 0}, 0xffff0000u},
	{{cos(M_PI * 2 / 3), sin(M_PI * 2 / 3)}, 0xff00ff00u},
	{{cos(M_PI * 4 / 3), sin(M_PI * 4 / 3)}, 0xff0000ffu},
};

static constexpr uint16_t TRIANGLE_INDICES[3] = { 0, 1, 2 };

Skybox* skybox;
VertexBuffer* vb;
IndexBuffer* ib;
Material* mat;
Entity renderable;
Entity camera;

void setup(Engine* engine, View* view, Scene* scene)
{
	// Ìì¿ÕºÐ
	skybox = Skybox::Builder()
		.color({ 0.0, 0.0, 1.0, 1.0 })
		.build(*engine);
	scene->setSkybox(skybox);

	vb = VertexBuffer::Builder()
		.vertexCount(3)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT2, 0, 12)
		.attribute(VertexAttribute::COLOR, 0, VertexBuffer::AttributeType::UBYTE4, 8, 12)
		.normalized(VertexAttribute::COLOR)
		.build(*engine);
	vb->setBufferAt(*engine, 0,
		VertexBuffer::BufferDescriptor(TRIANGLE_VERTICES, 36, nullptr));
	ib = IndexBuffer::Builder()
		.indexCount(3)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*engine);
	ib->setBuffer(*engine,
		IndexBuffer::BufferDescriptor(TRIANGLE_INDICES, 6, nullptr));
	mat = Material::Builder()
		.package(RESOURCES_BAKEDCOLOR_DATA, RESOURCES_BAKEDCOLOR_SIZE)
		.build(*engine);
	renderable = EntityManager::get().create();
	RenderableManager::Builder(1)
		.boundingBox({ { -1, -1, -1 }, { 1, 1, 1 } })
		.material(0, mat->getDefaultInstance())
		.geometry(0, RenderableManager::PrimitiveType::TRIANGLES, vb, ib, 0, 3)
		.culling(false)
		.receiveShadows(false)
		.castShadows(false)
		.build(*engine, renderable);
	scene->addEntity(renderable);
	camera = EntityManager::get().create();
	Camera* cam = engine->createCamera(camera);
	view->setCamera(cam);
}

void cleanup(Engine* engine, View* view, Scene* scene)
{
	engine->destroy(skybox);
	engine->destroy(vb);
	engine->destroy(ib);
	engine->destroy(mat);
	engine->destroy(renderable);
	engine->destroy(camera);
	engine->destroyCameraComponent(camera);
	EntityManager::get().destroy(camera);
}
