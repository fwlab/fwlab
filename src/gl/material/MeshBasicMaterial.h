#ifndef FWLAB_MESH_BASIC_MATERIAL_H
#define FWLAB_MESH_BASIC_MATERIAL_H
#include "../Context.h"
#include "Material.h"

/// <summary>
/// »ù±¾²ÄÖÊ
/// </summary>
class MeshBasicMaterial : public Material
{
public:
	MeshBasicMaterial(Context* context);
	virtual ~MeshBasicMaterial();
};

#endif