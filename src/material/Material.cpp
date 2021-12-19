#include "resources/resources.h"
#include "Material.h"

Material::Material(Context* context)
{
	this->context = context;
}

Material::~Material()
{
	if (context && context->engine && material)
	{
		context->engine->destroy(material);
	}
}

Material* Material::create()
{
	return create(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE);
}

Material* Material::create(const void* payload, size_t size)
{
	material = filament::Material::Builder()
		.package(payload, size)
		.build(*context->engine);
	return this;
}

filament::MaterialInstance* Material::createInstance()
{
	return material->createInstance();
}

void Material::setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType)
{
	this->primitiveType = primitiveType;
}