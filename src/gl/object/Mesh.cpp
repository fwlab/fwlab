#include <utils/EntityManager.h>
#include "Mesh.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::object;

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	if (geometry)
	{
		delete geometry;
		geometry = nullptr;
	}
	if (material)
	{
		material->dispose();
		material = nullptr;
	}
}

void Mesh::create(BufferGeometry* geometry, Material* material)
{
	this->geometry = geometry;
	this->material = material;

	entity = utils::EntityManager::get().create();
	filament::RenderableManager::Builder(1)
		.boundingBox(*geometry->getBoundingBox())
		.geometry(0, material->getPrimitiveType(), geometry->getVertexBuffer(), geometry->getIndexBuffer())
		.material(0, material->getInstance())
		.culling(culling)
		.castShadows(castShadows)
		.receiveShadows(receiveShadows)
		.build(*engine, entity);
}