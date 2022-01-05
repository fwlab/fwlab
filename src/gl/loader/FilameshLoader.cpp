#include <filameshio/MeshReader.h>
#include "../core/BufferGeometry.h"
#include "FilameshLoader.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;
using namespace gl::object;
using namespace gl::loader;

FilameshLoader::FilameshLoader()
{

}

FilameshLoader::~FilameshLoader()
{

}

Mesh* FilameshLoader::load(void const* data, filament::MaterialInstance* defaultMaterial)
{
	auto mesh = filamesh::MeshReader::loadMeshFromBuffer(engine, data, nullptr, nullptr, defaultMaterial);

	auto geometry = new BufferGeometry();
	geometry->vertexBuffer = mesh.vertexBuffer;
	geometry->indexBuffer = mesh.indexBuffer;
	// geometry->boundingBox

	auto result = new Mesh();
	result->geometry = geometry;
	// result->material = defaultMaterial->getMaterial();
	result->entity = mesh.renderable;

	return result;
}