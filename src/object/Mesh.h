#ifndef FLLAB_OBJECT_MESH_H
#define FLLAB_OBJECT_MESH_H
#include <filament/Material.h>
#include <filament/RenderableManager.h>
#include <utils/Entity.h>
#include "../geometry/Geometry.h"
#include "Object3D.h"
#include "../Context.h"

/// <summary>
/// Íø¸ñ
/// </summary>
class Mesh : public Object3D
{
public:
	Mesh(Context* context);
	virtual ~Mesh();
	void create(Geometry* geometry, filament::Material* material);
	void setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType);
	filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;
	bool culling = true;
	bool castShadows = false;
	bool receiveShadows = false;
	Geometry* geometry = nullptr;
	filament::Material* material = nullptr;
	utils::Entity entity;
};

#endif