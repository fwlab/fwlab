#include <filameshio/MeshReader.h>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "FilameshLoader.h"
#include "../context/context.h"

namespace fwlab::loader
{
	object::Mesh* FilameshLoader::load(void const* data)
	{
		auto material = new material::Material();
		auto mesh = filamesh::MeshReader::loadMeshFromBuffer(app->getEngine(), data, nullptr, nullptr, material->getInstance());

		auto geometry = new core::BufferGeometry();
		geometry->setVertexBuffer(mesh.vertexBuffer);
		geometry->setIndexBuffer(mesh.indexBuffer);
		// TODO: compute bounding box: geometry->boundingBox

		auto result = new object::Mesh();
		result->setGeometry(geometry);
		result->setMaterial(material);
		result->setEntity(mesh.renderable);

		return result;
	}

	object::Mesh* FilameshLoader::load(const ::utils::Path& path, filamesh::MeshReader::MaterialRegistry materials)
	{
		auto material = new material::Material();
		auto mesh = filamesh::MeshReader::loadMeshFromFile(app->getEngine(), path, materials);

		auto geometry = new core::BufferGeometry();
		geometry->setVertexBuffer(mesh.vertexBuffer);
		geometry->setIndexBuffer(mesh.indexBuffer);
		// TODO: compute bounding box: geometry->boundingBox

		auto result = new object::Mesh();
		result->setGeometry(geometry);
		// TODO: assign material to result->material
		result->setMaterial(material);
		result->setEntity(mesh.renderable);

		return result;
	}
}