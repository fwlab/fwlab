#ifndef GL_MATERIAL_MATERIAL_H
#define GL_MATERIAL_MATERIAL_H
#include <stdint.h>
#include <unordered_map>
#include <vector>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include <filamat/MaterialBuilder.h>

namespace gl::material
{
	class Material
	{
	public:
		Material();
		Material(const void* payload, size_t size);
		virtual ~Material();
		filament::MaterialInstance* getInstance() const;
		void setInstance(filament::MaterialInstance* instance);
		filament::RenderableManager::PrimitiveType getPrimitiveType() const;
		void setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType);

		// material method
		filament::Material::BlendingMode getBlendingMode() const noexcept;
		filament::Material::CullingMode getCullingMode() const noexcept;
		filament::MaterialInstance const* getDefaultInstance() const noexcept;
		filament::Material::Interpolation getInterpolation() const noexcept;
		float getMaskThreshold() const noexcept;
		filament::MaterialDomain getMaterialDomain() const noexcept;
		char const* getName() const noexcept;
		uint8_t getParameterCount() const noexcept;
		size_t getParameters(filament::Material::ParameterInfo* parameters, size_t count) const noexcept;
		filament::RefractionMode getRefractionMode() const noexcept;
		filament::RefractionType getRefractionType() const noexcept;
		filament::AttributeBitset getRequiredAttributes() const noexcept;
		filament::Shading getShading() const noexcept;
		float getSpecularAntiAliasingThreshold() const noexcept;
		float getSpecularAntiAliasingVariance() const noexcept;
		filament::TransparencyMode getTransparencyMode() const noexcept;
		filament::VertexDomain getVertexDomain() const noexcept;
		bool hasParameter(const char* name) const noexcept;
		bool hasShadowMultiplier();
		bool hasSpecularAntiAliasing() const noexcept;
		bool isColorWriteEnabled() const noexcept;
		bool isDepthCullingEnabled();
		bool isDepthWriteEnabled() const noexcept;
		bool isDoubleSided() const noexcept;
		bool isSampler(const char* name) const noexcept;
		void setDefaultParameter(const char* name, filament::Texture const* texture,
			filament::TextureSampler const& sampler) noexcept;

	protected:
		void create(const void* payload, size_t size);
		filament::Material* material = nullptr;
		filament::MaterialInstance* instance = nullptr;
		filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;
	};
}

#endif