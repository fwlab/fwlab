#include <cmath>
#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include "Triangle.h"

using namespace filament;

struct Vertex {
	math::float2 position;
	uint32_t color;
};

static const Vertex TRIANGLE_VERTICES[3] = {
	{{1, 0}, 0xffff0000u},
	{{std::cos(M_PI * 2 / 3), std::sin(M_PI * 2 / 3)}, 0xff00ff00u},
	{{std::cos(M_PI * 4 / 3), std::sin(M_PI * 4 / 3)}, 0xff0000ffu},
};

static constexpr uint16_t TRIANGLE_INDICES[3] = { 0, 1, 2 };

Triangle::Triangle(Engine* engine, filament::Material* material)
{
	this->engine = engine;
	this->material = material;

	vertexBuffer = VertexBuffer::Builder()
		.vertexCount(3)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT2, 0, 12)
		.attribute(VertexAttribute::COLOR, 0, VertexBuffer::AttributeType::UBYTE4, 8, 12)
		.normalized(VertexAttribute::COLOR)
		.build(*engine);
	vertexBuffer->setBufferAt(*engine, 0,
		VertexBuffer::BufferDescriptor(TRIANGLE_VERTICES, 36, nullptr));
	indexBuffer = IndexBuffer::Builder()
		.indexCount(3)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*engine);
	indexBuffer->setBuffer(*engine,
		IndexBuffer::BufferDescriptor(TRIANGLE_INDICES, 6, nullptr));

	entity = utils::EntityManager::get().create();
	RenderableManager::Builder(1)
		.boundingBox({ { -1, -1, -1 }, { 1, 1, 1 } })
		.material(0, material->getDefaultInstance())
		.geometry(0, RenderableManager::PrimitiveType::TRIANGLES, vertexBuffer, indexBuffer, 0, 3)
		.culling(false)
		.receiveShadows(false)
		.castShadows(false)
		.build(*engine, entity);
}

Triangle::~Triangle()
{
	engine->destroy(entity);
	engine->destroy(material);
	engine->destroy(vertexBuffer);
	engine->destroy(indexBuffer);
}