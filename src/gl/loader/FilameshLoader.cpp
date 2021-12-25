#include <filameshio/MeshReader.h>
#include "../core/BufferGeometry.h"
#include "FilameshLoader.h"

using namespace gl::core;
using namespace gl::object;
using namespace gl::loader;

FilameshLoader::FilameshLoader(Context* context) : Loader(context)
{

}

FilameshLoader::~FilameshLoader()
{

}

Mesh* FilameshLoader::load(void const* data, filament::MaterialInstance* defaultMaterial)
{
	auto mesh = filamesh::MeshReader::loadMeshFromBuffer(context->engine, data, nullptr, nullptr, defaultMaterial);

	auto geometry = new BufferGeometry(context);
	geometry->vertexBuffer = mesh.vertexBuffer;
	geometry->indexBuffer = mesh.indexBuffer;
	// geometry->boundingBox

	auto result = new Mesh(context);
	result->geometry = geometry;
	// result->material = defaultMaterial->getMaterial();
	result->entity = mesh.renderable;

	return result;
}