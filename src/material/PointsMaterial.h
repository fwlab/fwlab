#ifndef FWLAB_POINTS_MATERIAL_H
#define FWLAB_POINTS_MATERIAL_H
#include "../Context.h"
#include "Material.h"

/// <summary>
/// µ„‘∆≤ƒ÷ 
/// </summary>
class PointsMaterial : public Material
{
public:
	PointsMaterial(Context* context);
	virtual ~PointsMaterial();
};

#endif