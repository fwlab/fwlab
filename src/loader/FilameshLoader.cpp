#include <filameshio/MeshReader.h>
#include "../geometry/Geometry.h"
#include "FilameshLoader.h"

FilameshLoader::FilameshLoader(Context* context) : Loader(context)
{

}

FilameshLoader::~FilameshLoader()
{

}

Mesh* FilameshLoader::load(void const* data, filament::MaterialInstance* defaultMaterial)
{
	auto mesh = filamesh::MeshReader::loadMeshFromBuffer(context->engine, data, nullptr, nullptr, defaultMaterial);

	auto geometry = new Geometry(context);
	geometry->vertexBuffer = mesh.vertexBuffer;
	geometry->indexBuffer = mesh.indexBuffer;
	// geometry->boundingBox

	auto result = new Mesh(context);
	result->geometry = geometry;
	// result->material = defaultMaterial->getMaterial();
	result->entity = mesh.renderable;

	return result;
}