#include <cmath>
#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include "Triangle.h"

using namespace filament;

Triangle::Triangle(Context* context, filament::Material* material)
{
	this->context = context;
	this->material = material;

	static float vertices[] = {
		-0.5, -0.5,
		0.5, -0.5,
		0.5, 0.5,
	};
	static unsigned short indices[] = {
		0, 1, 2,
	};

	vertexBuffer = VertexBuffer::Builder()
		.vertexCount(3)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT2)
		.build(*context->engine);
	vertexBuffer->setBufferAt(*context->engine, 0,
		VertexBuffer::BufferDescriptor(vertices, sizeof(vertices), nullptr));
	indexBuffer = IndexBuffer::Builder()
		.indexCount(3)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*context->engine);
	indexBuffer->setBuffer(*context->engine,
		IndexBuffer::BufferDescriptor(indices, sizeof(indices), nullptr));

	entity = utils::EntityManager::get().create();
	RenderableManager::Builder(1)
		.geometry(0, RenderableManager::PrimitiveType::TRIANGLES, vertexBuffer, indexBuffer)
		.material(0, material->getDefaultInstance())
		.boundingBox({ {-1, -1, -1}, {1, 1, 1} })
		.build(*context->engine, entity);
}

Triangle::~Triangle()
{
	context->engine->destroy(entity);
	context->engine->destroy(material);
	context->engine->destroy(vertexBuffer);
	context->engine->destroy(indexBuffer);
}