#ifndef GL_MATERIAL_POINTS_MATERIAL_H
#define GL_MATERIAL_POINTS_MATERIAL_H
#include "../Context.h"
#include "Material.h"

namespace gl::material
{
	class PointsMaterial : public Material
	{
	public:
		PointsMaterial(Context* context);
		virtual ~PointsMaterial();
	};
}

#endif