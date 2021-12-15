#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include "Rectangle.h"

using namespace filament;

Rectangle::Rectangle(Context* context, filament::Material* material)
{
	this->context = context;
	this->material = material;

	float vertices[] = {
		-0.5, -0.5,
		0.5, -0.5,
		0.5, 0.5,
		-0.5, 0.5,
	};
	unsigned short indices[] = {
		0, 1, 2,
		0, 2, 3,
		0, 2, 1,
		0, 3, 2
	};

	// 顶点
	vertexBuffer = VertexBuffer::Builder()
		.vertexCount(4)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT2)
		.build(*context->engine);
	vertexBuffer->setBufferAt(
		*context->engine, 0,
		VertexBuffer::BufferDescriptor(vertices, sizeof(vertices)));

	// 索引
	indexBuffer = IndexBuffer::Builder()
		.indexCount(12)
		.bufferType(IndexBuffer::IndexType::USHORT)
		.build(*context->engine);
	indexBuffer->setBuffer(
		*context->engine,
		IndexBuffer::BufferDescriptor(indices, sizeof(indices))
	);

	// 物体
	entity = utils::EntityManager::get().create();
	RenderableManager::Builder(1)
		.boundingBox({ {-1, -1, -1}, { 1, 1, 1 } })
		.geometry(0, RenderableManager::PrimitiveType::TRIANGLES, vertexBuffer, indexBuffer)
		.material(0, material->getDefaultInstance())
		.culling(false)
		.castShadows(false)
		.receiveShadows(false)
		.build(*context->engine, entity);
}

Rectangle::~Rectangle()
{
	context->engine->destroy(entity);
	context->engine->destroy(material);
	context->engine->destroy(vertexBuffer);
	context->engine->destroy(indexBuffer);
}