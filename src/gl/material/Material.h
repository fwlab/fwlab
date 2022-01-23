#ifndef GL_MATERIAL_MATERIAL_H
#define GL_MATERIAL_MATERIAL_H
#include <stdint.h>
#include <unordered_map>
#include <vector>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include <filamat/MaterialBuilder.h>
#include <math/vec3.h>
#include <math/vec4.h>
#include "../core/IDisposable.h"

namespace gl::material
{
	class Material : public gl::core::IDisposable
	{
	public:
		Material();
		Material(const void *payload, size_t size);
		Material(filament::MaterialInstance *instance);
		virtual ~Material();
		filament::MaterialInstance *getInstance() const;
		void setInstance(filament::MaterialInstance *instance);
		filament::RenderableManager::PrimitiveType getPrimitiveType() const;
		void setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType);
		void dispose() override;

		// material method
		filament::Material::BlendingMode getBlendingMode() const noexcept;
		filament::Material::CullingMode getCullingMode() const noexcept;
		filament::MaterialInstance const *getDefaultInstance() const noexcept;
		filament::Material::Interpolation getInterpolation() const noexcept;
		float getMaskThreshold() const noexcept;
		filament::MaterialDomain getMaterialDomain() const noexcept;
		char const *getName() const noexcept;
		uint8_t getParameterCount() const noexcept;
		size_t getParameters(filament::Material::ParameterInfo *parameters, size_t count) const noexcept;
		filament::RefractionMode getRefractionMode() const noexcept;
		filament::RefractionType getRefractionType() const noexcept;
		filament::AttributeBitset getRequiredAttributes() const noexcept;
		filament::Shading getShading() const noexcept;
		float getSpecularAntiAliasingThreshold() const noexcept;
		float getSpecularAntiAliasingVariance() const noexcept;
		filament::TransparencyMode getTransparencyMode() const noexcept;
		filament::VertexDomain getVertexDomain() const noexcept;
		bool hasParameter(const char *name) const noexcept;
		bool hasShadowMultiplier();
		bool hasSpecularAntiAliasing() const noexcept;
		bool isColorWriteEnabled() const noexcept;
		bool isDepthCullingEnabled();
		bool isDepthWriteEnabled() const noexcept;
		bool isDoubleSided() const noexcept;
		bool isSampler(const char *name) const noexcept;
		template <typename T>
		void setDefaultParameter(const char *name, T value) noexcept;
		void setDefaultParameter(const char *name, filament::Texture const *texture,
								 filament::TextureSampler const &sampler) noexcept;
		void setDefaultParameter(const char *name, filament::RgbType type, filament::math::float3 color) noexcept;
		void setDefaultParameter(const char *name, filament::RgbaType type, filament::math::float4 color) noexcept;

		// instance
		void setColorWrite(bool enable) noexcept;
		void setCullingMode(filament::MaterialInstance::CullingMode culling) noexcept;
		void setDepthCulling(bool enable) noexcept;
		void setDepthWrite(bool enable) noexcept;
		void setDoubleSided(bool doubleSided) noexcept;
		void setMaskThreshold(float threshold) noexcept;
		template <typename T>
		void setParameter(const char *name, T value) noexcept;
		template <typename T>
		void setParameter(const char *name, T *value, size_t count) noexcept;
		// template <>
		// void setParameter<filament::math::mat3f>(const char *name, filament::math::mat3f *value, size_t count) noexcept;
		void setParameter(const char *name, filament::Texture const *texture,
						  filament::TextureSampler const &sampler) noexcept;
		void setParameter(const char *name, filament::RgbType type, filament::math::float3 color) noexcept;
		void setParameter(const char *name, filament::RgbaType type, filament::math::float4 color) noexcept;
		void setPolygonOffset(float scale, float constant) noexcept;
		void setScissor(uint32_t left, uint32_t bottom, uint32_t width, uint32_t height) noexcept;
		void setSpecularAntiAliasingThreshold(float threshold) noexcept;
		void setSpecularAntiAliasingVariance(float variance) noexcept;
		void setTransparencyMode(filament::MaterialInstance::TransparencyMode mode) noexcept;
		void unsetScissor();

	protected:
		void create(const void *payload, size_t size);
		filament::Material *material = nullptr;
		filament::MaterialInstance *instance = nullptr;
		filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;
	};
}

#endif