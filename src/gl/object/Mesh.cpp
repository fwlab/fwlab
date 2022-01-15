#include <utils/EntityManager.h>
#include "Mesh.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;
using namespace gl::material;
using namespace gl::object;

Mesh::Mesh()
{

}

Mesh::Mesh(BufferGeometry* geometry, Material* material)
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

bool Mesh::getCulling() const noexcept
{
	return culling;
}

void Mesh::setCulling(bool culling) noexcept
{
	this->culling = culling;
}

bool Mesh::getCastShadows() const noexcept
{
	return castShadows;
}

void Mesh::setCastShadows(bool castShadows) noexcept
{
	this->castShadows = castShadows;
}

bool Mesh::getReceiveShadows() const noexcept
{
	return receiveShadows;
}

void Mesh::setReceiveShadows(bool receiveShadows) noexcept
{
	this->receiveShadows = receiveShadows;
}

gl::core::BufferGeometry* Mesh::getGeometry() const noexcept
{
	return geometry;
}

void Mesh::setGeometry(gl::core::BufferGeometry* geometry) noexcept
{
	this->geometry = geometry;
}

gl::material::Material* Mesh::getMaterial() const noexcept
{
	return material;
}

void Mesh::setMaterial(gl::material::Material* material) noexcept
{
	this->material = material;
}