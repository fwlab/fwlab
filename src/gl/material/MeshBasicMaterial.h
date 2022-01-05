#ifndef GL_MATERIAL_MESH_BASIC_MATERIAL_H
#define GL_MATERIAL_MESH_BASIC_MATERIAL_H
#include "Material.h"

namespace gl::material
{
	class MeshBasicMaterial : public Material
	{
	public:
		MeshBasicMaterial();
		virtual ~MeshBasicMaterial();
	};
}

#endif