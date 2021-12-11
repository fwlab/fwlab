#include <filament/Skybox.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include "generated/resources/resources.h"
#include "scene.h"

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

filament::Skybox* skybox;
filament::VertexBuffer* vb;
filament::IndexBuffer* ib;
filament::Material* mat;
utils::Entity renderable;
utils::Entity camera;

void Scene::setup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	// Ìì¿ÕºÐ
	skybox = filament::Skybox::Builder()
		.color({ 0.0, 0.0, 1.0, 1.0 })
		.build(*engine);
	scene->setSkybox(skybox);

	vb = filament::VertexBuffer::Builder()
		.vertexCount(3)
		.bufferCount(1)
		.attribute(filament::VertexAttribute::POSITION, 0, filament::VertexBuffer::AttributeType::FLOAT2, 0, 12)
		.attribute(filament::VertexAttribute::COLOR, 0, filament::VertexBuffer::AttributeType::UBYTE4, 8, 12)
		.normalized(filament::VertexAttribute::COLOR)
		.build(*engine);
	vb->setBufferAt(*engine, 0,
		filament::VertexBuffer::BufferDescriptor(TRIANGLE_VERTICES, 36, nullptr));
	ib = filament::IndexBuffer::Builder()
		.indexCount(3)
		.bufferType(filament::IndexBuffer::IndexType::USHORT)
		.build(*engine);
	ib->setBuffer(*engine,
		filament::IndexBuffer::BufferDescriptor(TRIANGLE_INDICES, 6, nullptr));
	mat = filament::Material::Builder()
		.package(RESOURCES_BAKEDCOLOR_DATA, RESOURCES_BAKEDCOLOR_SIZE)
		.build(*engine);
	renderable = utils::EntityManager::get().create();
	filament::RenderableManager::Builder(1)
		.boundingBox({ { -1, -1, -1 }, { 1, 1, 1 } })
		.material(0, mat->getDefaultInstance())
		.geometry(0, filament::RenderableManager::PrimitiveType::TRIANGLES, vb, ib, 0, 3)
		.culling(false)
		.receiveShadows(false)
		.castShadows(false)
		.build(*engine, renderable);
	scene->addEntity(renderable);
	camera = utils::EntityManager::get().create();
	filament::Camera* cam = engine->createCamera(camera);
	view->setCamera(cam);
}

void Scene::cleanup(filament::Engine* engine, filament::View* view, filament::Scene* scene)
{
	engine->destroy(skybox);
	engine->destroy(vb);
	engine->destroy(ib);
	engine->destroy(mat);
	engine->destroy(renderable);
	engine->destroy(camera);
	engine->destroyCameraComponent(camera);
	utils::EntityManager::get().destroy(camera);
}