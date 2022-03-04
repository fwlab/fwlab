#ifndef FWLAB_MATERIAL_MATERIAL_H
#define FWLAB_MATERIAL_MATERIAL_H
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

namespace fwlab::material
{
	class Material : public core::IDisposable
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
		filament::Material::BlendingMode getBlendingMode() const;
		filament::Material::CullingMode getCullingMode() const;
		filament::MaterialInstance const *getDefaultInstance() const;
		filament::Material::Interpolation getInterpolation() const;
		float getMaskThreshold() const;
		filament::MaterialDomain getMaterialDomain() const;
		char const *getName() const;
		uint8_t getParameterCount() const;
		size_t getParameters(filament::Material::ParameterInfo *parameters, size_t count) const;
		filament::RefractionMode getRefractionMode() const;
		filament::RefractionType getRefractionType() const;
		filament::AttributeBitset getRequiredAttributes() const;
		filament::Shading getShading() const;
		float getSpecularAntiAliasingThreshold() const;
		float getSpecularAntiAliasingVariance() const;
		filament::TransparencyMode getTransparencyMode() const;
		filament::VertexDomain getVertexDomain() const;
		bool hasParameter(const char *name) const;
		bool hasShadowMultiplier();
		bool hasSpecularAntiAliasing() const;
		bool isColorWriteEnabled() const;
		bool isDepthCullingEnabled();
		bool isDepthWriteEnabled() const;
		bool isDoubleSided() const;
		bool isSampler(const char *name) const;
		template <typename T>
		void setDefaultParameter(const char *name, T value);
		void setDefaultParameter(const char *name, filament::Texture const *texture,
								 filament::TextureSampler const &sampler);
		void setDefaultParameter(const char *name, filament::RgbType type, filament::math::float3 color);
		void setDefaultParameter(const char *name, filament::RgbaType type, filament::math::float4 color);

		// instance
		void setColorWrite(bool enable);
		void setCullingMode(filament::MaterialInstance::CullingMode culling);
		void setDepthCulling(bool enable);
		void setDepthWrite(bool enable);
		void setDoubleSided(bool doubleSided);
		void setMaskThreshold(float threshold);
		template <typename T>
		void setParameter(const char *name, T value);
		template <typename T>
		void setParameter(const char *name, T *value, size_t count);
		// template <>
		// void setParameter<filament::math::mat3f>(const char *name, filament::math::mat3f *value, size_t count);
		void setParameter(const char *name, filament::Texture const *texture,
						  filament::TextureSampler const &sampler);
		void setParameter(const char *name, filament::RgbType type, filament::math::float3 color);
		void setParameter(const char *name, filament::RgbaType type, filament::math::float4 color);
		void setPolygonOffset(float scale, float constant);
		void setScissor(uint32_t left, uint32_t bottom, uint32_t width, uint32_t height);
		void setSpecularAntiAliasingThreshold(float threshold);
		void setSpecularAntiAliasingVariance(float variance);
		void setTransparencyMode(filament::MaterialInstance::TransparencyMode mode);
		void unsetScissor();

	protected:
		void create(const void *payload, size_t size);
		filament::Material *material = nullptr;
		filament::MaterialInstance *instance = nullptr;
		filament::RenderableManager::PrimitiveType primitiveType = filament::RenderableManager::PrimitiveType::TRIANGLES;
	};
}

#endif