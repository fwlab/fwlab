#include <utils/EntityManager.h>
#include "Mesh.h"

using namespace gl::object;

Mesh::Mesh(Context* context) : Object3D(context)
{

}

Mesh::~Mesh()
{

}

void Mesh::create(BufferGeometry* geometry, Material* material)
{
	this->geometry = geometry;
	this->material = material;

	entity = utils::EntityManager::get().create();
	filament::RenderableManager::Builder(1)
		.boundingBox(*geometry->boundingBox)
		.geometry(0, material->primitiveType, geometry->vertexBuffer, geometry->indexBuffer)
		.material(0, material->instance)
		.culling(culling)
		.castShadows(castShadows)
		.receiveShadows(receiveShadows)
		.build(*context->engine, entity);
}