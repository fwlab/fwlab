#ifndef GL_MATERIAL_LINE_BASIC_MATERIAL_H
#define GL_MATERIAL_LINE_BASIC_MATERIAL_H
#include "Material.h"

namespace gl::material
{
	class LineBasicMaterial : public Material
	{
	public:
		LineBasicMaterial();
		virtual ~LineBasicMaterial();
	};
}

#endif