#include <filameshio/MeshReader.h>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "FilameshLoader.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;
using namespace gl::material;
using namespace gl::object;
using namespace gl::loader;

Mesh *FilameshLoader::load(void const *data)
{
	auto material = new Material();
	auto mesh = filamesh::MeshReader::loadMeshFromBuffer(engine, data, nullptr, nullptr, material->getInstance());

	auto geometry = new BufferGeometry();
	geometry->setVertexBuffer(mesh.vertexBuffer);
	geometry->setIndexBuffer(mesh.indexBuffer);
	// TODO: compute bounding box: geometry->boundingBox

	auto result = new Mesh();
	result->setGeometry(geometry);
	result->setMaterial(material);
	result->setEntity(mesh.renderable);

	return result;
}

gl::object::Mesh *FilameshLoader::load(const utils::Path &path, filamesh::MeshReader::MaterialRegistry materials)
{
	auto material = new Material();
	auto mesh = filamesh::MeshReader::loadMeshFromFile(engine, path, materials);

	auto geometry = new BufferGeometry();
	geometry->setVertexBuffer(mesh.vertexBuffer);
	geometry->setIndexBuffer(mesh.indexBuffer);
	// TODO: compute bounding box: geometry->boundingBox

	auto result = new Mesh();
	result->setGeometry(geometry);
	// TODO: assign material to result->material
	result->setMaterial(material);
	result->setEntity(mesh.renderable);

	return result;
}