#ifndef FWLAB_MATERIAL_H
#define FWLAB_MATERIAL_H
#include <vector>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include "../Context.h"

/// <summary>
/// ²ÄÖÊ
/// </summary>
class Material
{
public:
	Material(Context* context);
	virtual ~Material();
	virtual void create();
	filament::MaterialInstance* instance = nullptr;
	filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;

protected:
	void createMaterial(const void* payload, size_t size);
	Context* context = nullptr;
	static filament::Material* material;
	static std::vector<filament::MaterialInstance*> instances;
};

#endif