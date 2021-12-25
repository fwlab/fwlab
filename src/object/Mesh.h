#ifndef FLLAB_OBJECT_MESH_H
#define FLLAB_OBJECT_MESH_H
#include <utils/Entity.h>
#include "../geometry/Geometry.h"
#include "../material/Material.h"
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
	void create(Geometry* geometry, Material* material);
	bool culling = true;
	bool castShadows = false;
	bool receiveShadows = false;
	Geometry* geometry = nullptr;
	Material* material = nullptr;
};

#endif