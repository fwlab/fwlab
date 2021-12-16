#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include "Line.h"

using namespace filament;

Line::Line(Context* context, filament::Material* material)
{
	this->context = context;
	this->material = material;

	static float vertices[] = {
		-0.5, 0,
		0.5, 0,
	};

	static unsigned short indices[] = {
		0, 1,
	};

	// 顶点
	vertexBuffer = VertexBuffer::Builder()
		.vertexCount(2)
		.bufferCount(1)
		.attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT2)
		.build(*context->engine);
	vertexBuffer->setBufferAt(
		*context->engine, 0,
		VertexBuffer::BufferDescriptor(vertices, sizeof(vertices)));

	// 索引
	indexBuffer = IndexBuffer::Builder()
		.indexCount(2)
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
		.geometry(0, RenderableManager::PrimitiveType::LINES, vertexBuffer, indexBuffer)
		.material(0, material->getDefaultInstance())
		.culling(false)
		.castShadows(false)
		.receiveShadows(false)
		.build(*context->engine, entity);
}

Line::~Line()
{
	context->engine->destroy(entity);
	context->engine->destroy(material);
	context->engine->destroy(vertexBuffer);
	context->engine->destroy(indexBuffer);
}