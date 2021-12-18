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
	material = filament::Material::Builder()
		.package(RESOURCES_DEFAULTMATERIAL_DATA, RESOURCES_DEFAULTMATERIAL_SIZE)
		.build(*context->engine);
	return this;
}

void Material::setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType)
{
	this->primitiveType = primitiveType;
}