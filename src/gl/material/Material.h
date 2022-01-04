#ifndef GL_MATERIAL_MATERIAL_H
#define GL_MATERIAL_MATERIAL_H
#include <vector>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include "../Context.h"

namespace gl::material
{
	class Material
	{
	public:
		Material(Context* context);
		virtual ~Material();
		virtual void create();
		virtual void create(const void* payload, size_t size);
		filament::MaterialInstance* instance = nullptr;
		filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;

	protected:
		void createMaterial(const void* payload, size_t size);
		Context* context = nullptr;
		static filament::Material* material;
		static std::vector<filament::MaterialInstance*> instances;
	};
}

#endif