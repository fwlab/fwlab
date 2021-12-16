#include <utils/EntityManager.h>
#include "Mesh.h"

Mesh::Mesh(Context* context) : Object3D(context)
{

}

Mesh::~Mesh()
{
	if (context && context->engine && entity)
	{
		context->engine->destroy(entity);
	}
}

void Mesh::setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType)
{
	this->primitiveType = primitiveType;
}

void Mesh::create(Geometry* geometry, filament::Material* material)
{
	this->geometry = geometry;
	this->material = material;

	entity = utils::EntityManager::get().create();
	filament::RenderableManager::Builder(1)
		.boundingBox(*geometry->boundingBox)
		.geometry(0, primitiveType, geometry->vertexBuffer, geometry->indexBuffer)
		.material(0, material->getDefaultInstance())
		.culling(culling)
		.castShadows(castShadows)
		.receiveShadows(receiveShadows)
		.build(*context->engine, entity);
}