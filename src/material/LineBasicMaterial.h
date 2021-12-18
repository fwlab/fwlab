#ifndef FWLAB_LINE_BASIC_MATERIAL_H
#define FWLAB_LINE_BASIC_MATERIAL_H
#include "../Context.h"
#include "Material.h"

/// <summary>
/// »ù±¾²ÄÖÊ
/// </summary>
class LineBasicMaterial : public Material
{
public:
	LineBasicMaterial(Context* context);
	virtual ~LineBasicMaterial();
};

#endif