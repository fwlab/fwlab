#ifndef GL_MATERIAL_POINTS_MATERIAL_H
#define GL_MATERIAL_POINTS_MATERIAL_H
#include "Material.h"

namespace gl::material
{
	class PointsMaterial : public Material
	{
	public:
		PointsMaterial();
		virtual ~PointsMaterial();
	};
}

#endif