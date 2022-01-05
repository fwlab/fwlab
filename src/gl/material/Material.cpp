#include <algorithm>
#include "resources/resources.h"
#include "Material.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::material;

filament::Material* Material::material = nullptr;
std::vector<filament::MaterialInstance*> Material::instances;

Material::Material()
{
}

Material::~Material()
{
	if (instances.size() > 0 && instance)
	{
		instances.erase(std::remove(instances.begin(), instances.end(), instance));
		engine->destroy(instance);
	}
	if (material && instances.size() == 0)
	{
		engine->destroy(material);
	}
}

void Material::create()
{
	createMaterial(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE);
}

void Material::create(const void* payload, size_t size)
{
	createMaterial(payload, size);
}

void Material::createMaterial(const void* payload, size_t size)
{
	if (!material)
	{
		material = filament::Material::Builder()
			.package(payload, size)
			.build(*engine);
	}
	instance = material->createInstance();
	instances.push_back(instance);
}
