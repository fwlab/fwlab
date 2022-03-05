#include <algorithm>
#include <resources/resources.h>
#include "Material.h"
#include "../context/context.h"

namespace fwlab::material
{
	static std::unordered_map<const void*, filament::Material*> materials;
	static std::vector<filament::MaterialInstance*> instances;

	Material::Material() : Material(RESOURCES_UNLIT_DATA, RESOURCES_UNLIT_SIZE)
	{
		setParameter<filament::math::float4>("baseColor", { 1, 1, 1, 1 });
	}

	Material::Material(const void* payload, size_t size)
	{
		create(payload, size);
	}

	Material::Material(filament::MaterialInstance* instance)
	{
		this->material = const_cast<filament::Material*>(instance->getMaterial());
		this->instance = instance;
		instances.push_back(instance);
	}

	Material::~Material()
	{
		dispose();
	}

	filament::MaterialInstance* Material::getInstance() const
	{
		return instance;
	}

	void Material::setInstance(filament::MaterialInstance* instance)
	{
		if (instance == this->instance)
		{
			return;
		}
		if (instances.size() > 0 && this->instance)
		{
			instances.erase(std::remove(instances.begin(), instances.end(), this->instance));
			app->getEngine()->destroy(this->instance);
		}
		this->instance = instance;
		instances.push_back(instance);
	}

	filament::RenderableManager::PrimitiveType Material::getPrimitiveType() const
	{
		return primitiveType;
	}

	void Material::setPrimitiveType(filament::RenderableManager::PrimitiveType primitiveType)
	{
		this->primitiveType = primitiveType;
	}

	void Material::dispose()
	{
		auto engine = app->getEngine();

		if (instances.size() > 0 && instance)
		{
			instances.erase(std::remove(instances.begin(), instances.end(), instance));
			engine->destroy(instance);
			instance = nullptr;
		}
		if (material && instances.size() == 0)
		{
			engine->destroy(material);
			material = nullptr;
		}
	}

	void Material::create(const void* payload, size_t size)
	{
		if (materials.find(payload) != materials.end())
		{
			material = materials.at(payload);
		}
		else
		{
			material = filament::Material::Builder()
				.package(payload, size)
				.build(*app->getEngine());
			materials.insert({ payload, material });
		}

		instance = material->createInstance();
		instances.push_back(instance);
	}

	// material method

	filament::Material::BlendingMode Material::getBlendingMode() const
	{
		return material->getBlendingMode();
	}

	filament::Material::CullingMode Material::getCullingMode() const
	{
		return material->getCullingMode();
	}

	filament::MaterialInstance const* Material::getDefaultInstance() const
	{
		return material->getDefaultInstance();
	}

	filament::Material::Interpolation Material::getInterpolation() const
	{
		return material->getInterpolation();
	}

	float Material::getMaskThreshold() const
	{
		return material->getMaskThreshold();
	}

	filament::MaterialDomain Material::getMaterialDomain() const
	{
		return material->getMaterialDomain();
	}

	char const* Material::getName() const
	{
		return material->getName();
	}

	uint8_t Material::getParameterCount() const
	{
		return material->getParameterCount();
	}

	size_t Material::getParameters(filament::Material::ParameterInfo* parameters, size_t count) const
	{
		return material->getParameters(parameters, count);
	}

	filament::RefractionMode Material::getRefractionMode() const
	{
		return material->getRefractionMode();
	}

	filament::RefractionType Material::getRefractionType() const
	{
		return material->getRefractionType();
	}

	filament::AttributeBitset Material::getRequiredAttributes() const
	{
		return material->getRequiredAttributes();
	}

	filament::Shading Material::getShading() const
	{
		return material->getShading();
	}

	float Material::getSpecularAntiAliasingThreshold() const
	{
		return material->getSpecularAntiAliasingThreshold();
	}

	float Material::getSpecularAntiAliasingVariance() const
	{
		return material->getSpecularAntiAliasingVariance();
	}

	filament::TransparencyMode Material::getTransparencyMode() const
	{
		return material->getTransparencyMode();
	}

	filament::VertexDomain Material::getVertexDomain() const
	{
		return material->getVertexDomain();
	}

	bool Material::hasParameter(const char* name) const
	{
		return material->hasParameter(name);
	}

	bool Material::hasShadowMultiplier()
	{
		return material->hasShadowMultiplier();
	}

	bool Material::hasSpecularAntiAliasing() const
	{
		return material->hasSpecularAntiAliasing();
	}

	bool Material::isColorWriteEnabled() const
	{
		return material->isColorWriteEnabled();
	}

	bool Material::isDepthCullingEnabled()
	{
		return material->isDepthCullingEnabled();
	}

	bool Material::isDepthWriteEnabled() const
	{
		return material->isDepthWriteEnabled();
	}

	bool Material::isDoubleSided() const
	{
		return material->isDoubleSided();
	}

	bool Material::isSampler(const char* name) const
	{
		return material->isSampler(name);
	}

	template <typename T>
	void Material::setDefaultParameter(const char* name, T value)
	{
		return material->setDefaultParameter(name, value);
	}

	template void Material::setDefaultParameter<float>(const char* name, float value);
	template void Material::setDefaultParameter<int32_t>(const char* name, int32_t value);
	template void Material::setDefaultParameter<uint32_t>(const char* name, uint32_t value);
	template void Material::setDefaultParameter<filament::math::int2>(const char* name, filament::math::int2 value);
	template void Material::setDefaultParameter<filament::math::int3>(const char* name, filament::math::int3 value);
	template void Material::setDefaultParameter<filament::math::int4>(const char* name, filament::math::int4 value);
	template void Material::setDefaultParameter<filament::math::uint2>(const char* name, filament::math::uint2 value);
	template void Material::setDefaultParameter<filament::math::uint3>(const char* name, filament::math::uint3 value);
	template void Material::setDefaultParameter<filament::math::uint4>(const char* name, filament::math::uint4 value);
	template void Material::setDefaultParameter<filament::math::float2>(const char* name, filament::math::float2 value);
	template void Material::setDefaultParameter<filament::math::float3>(const char* name, filament::math::float3 value);
	template void Material::setDefaultParameter<filament::math::float4>(const char* name, filament::math::float4 value);
	template void Material::setDefaultParameter<filament::math::mat3f>(const char* name, filament::math::mat3f value);
	template void Material::setDefaultParameter<filament::math::mat4f>(const char* name, filament::math::mat4f value);

	void Material::setDefaultParameter(const char* name, filament::Texture const* texture,
		filament::TextureSampler const& sampler)
	{
		return material->setDefaultParameter(name, texture, sampler);
	}

	void Material::setDefaultParameter(const char* name, filament::RgbType type, filament::math::float3 color)
	{
		return material->setDefaultParameter(name, type, color);
	}

	void Material::setDefaultParameter(const char* name, filament::RgbaType type, filament::math::float4 color)
	{
		return material->setDefaultParameter(name, type, color);
	}

	// instance

	void Material::setColorWrite(bool enable)
	{
		return instance->setColorWrite(enable);
	}

	void Material::setCullingMode(filament::MaterialInstance::CullingMode culling)
	{
		return instance->setCullingMode(culling);
	}

	void Material::setDepthCulling(bool enable)
	{
		return instance->setDepthCulling(enable);
	}

	void Material::setDepthWrite(bool enable)
	{
		return instance->setDepthWrite(enable);
	}

	void Material::setDoubleSided(bool doubleSided)
	{
		return instance->setDoubleSided(doubleSided);
	}

	void Material::setMaskThreshold(float threshold)
	{
		return instance->setMaskThreshold(threshold);
	}

	template <typename T>
	void Material::setParameter(const char* name, T value)
	{
		return instance->setParameter(name, value);
	}

	template void Material::setParameter<float>(const char* name, float value);
	template void Material::setParameter<int32_t>(const char* name, int32_t value);
	template void Material::setParameter<uint32_t>(const char* name, uint32_t value);
	template void Material::setParameter<bool>(const char* name, bool value);
	template void Material::setParameter<filament::math::bool2>(const char* name, filament::math::bool2 value);
	template void Material::setParameter<filament::math::bool3>(const char* name, filament::math::bool3 value);
	template void Material::setParameter<filament::math::bool4>(const char* name, filament::math::bool4 value);
	template void Material::setParameter<filament::math::int2>(const char* name, filament::math::int2 value);
	template void Material::setParameter<filament::math::int3>(const char* name, filament::math::int3 value);
	template void Material::setParameter<filament::math::int4>(const char* name, filament::math::int4 value);
	template void Material::setParameter<filament::math::uint2>(const char* name, filament::math::uint2 value);
	template void Material::setParameter<filament::math::uint3>(const char* name, filament::math::uint3 value);
	template void Material::setParameter<filament::math::uint4>(const char* name, filament::math::uint4 value);
	template void Material::setParameter<filament::math::float2>(const char* name, filament::math::float2 value);
	template void Material::setParameter<filament::math::float3>(const char* name, filament::math::float3 value);
	template void Material::setParameter<filament::math::float4>(const char* name, filament::math::float4 value);
	template void Material::setParameter<filament::math::mat3f>(const char* name, filament::math::mat3f value);
	template void Material::setParameter<filament::math::mat4f>(const char* name, filament::math::mat4f value);

	template <typename T>
	void Material::setParameter(const char* name, T* value, size_t count)
	{
		return instance->setParameter(name, value, count);
	}

	template void Material::setParameter<float>(const char* name, float* value, size_t count);
	template void Material::setParameter<int32_t>(const char* name, int32_t* value, size_t count);
	template void Material::setParameter<uint32_t>(const char* name, uint32_t* value, size_t count);
	template void Material::setParameter<bool>(const char* name, bool* value, size_t count);
	template void Material::setParameter<filament::math::bool2>(const char* name, filament::math::bool2* value, size_t count);
	template void Material::setParameter<filament::math::bool3>(const char* name, filament::math::bool3* value, size_t count);
	template void Material::setParameter<filament::math::bool4>(const char* name, filament::math::bool4* value, size_t count);
	template void Material::setParameter<filament::math::int2>(const char* name, filament::math::int2* value, size_t count);
	template void Material::setParameter<filament::math::int3>(const char* name, filament::math::int3* value, size_t count);
	template void Material::setParameter<filament::math::int4>(const char* name, filament::math::int4* value, size_t count);
	template void Material::setParameter<filament::math::uint2>(const char* name, filament::math::uint2* value, size_t count);
	template void Material::setParameter<filament::math::uint3>(const char* name, filament::math::uint3* value, size_t count);
	template void Material::setParameter<filament::math::uint4>(const char* name, filament::math::uint4* value, size_t count);
	template void Material::setParameter<filament::math::float2>(const char* name, filament::math::float2* value, size_t count);
	template void Material::setParameter<filament::math::float3>(const char* name, filament::math::float3* value, size_t count);
	template void Material::setParameter<filament::math::float4>(const char* name, filament::math::float4* value, size_t count);
	template void Material::setParameter<filament::math::mat4f>(const char* name, filament::math::mat4f* value, size_t count);

	template <>
	void Material::setParameter<filament::math::mat3f>(const char* name, filament::math::mat3f* value, size_t count)
	{
		return instance->setParameter(name, value, count);
	}

	void Material::setParameter(const char* name, filament::Texture const* texture,
		filament::TextureSampler const& sampler)
	{
		return instance->setParameter(name, texture, sampler);
	}

	void Material::setParameter(const char* name, filament::RgbType type, filament::math::float3 color)
	{
		return instance->setParameter(name, type, color);
	}

	void Material::setParameter(const char* name, filament::RgbaType type, filament::math::float4 color)
	{
		return instance->setParameter(name, type, color);
	}

	void Material::setPolygonOffset(float scale, float constant)
	{
		return instance->setPolygonOffset(scale, constant);
	}

	void Material::setScissor(uint32_t left, uint32_t bottom, uint32_t width, uint32_t height)
	{
		return instance->setScissor(left, bottom, width, height);
	}

	void Material::setSpecularAntiAliasingThreshold(float threshold)
	{
		return instance->setSpecularAntiAliasingThreshold(threshold);
	}

	void Material::setSpecularAntiAliasingVariance(float variance)
	{
		return instance->setSpecularAntiAliasingVariance(variance);
	}

	void Material::setTransparencyMode(filament::MaterialInstance::TransparencyMode mode)
	{
		return instance->setTransparencyMode(mode);
	}

	void Material::unsetScissor()
	{
		return instance->unsetScissor();
	}
}