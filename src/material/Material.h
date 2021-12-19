#ifndef FWLAB_MATERIAL_H
#define FWLAB_MATERIAL_H
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include "../Context.h"

/// <summary>
/// ����
/// </summary>
class Material
{
public:
	Material(Context* context);
	virtual ~Material();
	Material* create();
	Material* create(const void* payload, size_t size);
	filament::MaterialInstance* createInstance();
	filament::Material* material = nullptr;
	void setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType);
	filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;

protected:
	Context* context = nullptr;
};

#endif