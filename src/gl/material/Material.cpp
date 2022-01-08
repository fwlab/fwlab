#include <algorithm>
#include "resources/resources.h"
#include "Material.h"
#include "../context/context.h"

using namespace filament::math;
using namespace gl::context;
using namespace gl::material;

static std::unordered_map<const void*, filament::Material*> materials;
static std::vector<filament::MaterialInstance*> instances;

Material::Material() : Material(RESOURCES_LIT_DATA, RESOURCES_LIT_SIZE)
{
}

Material::Material(const void* payload, size_t size)
{
	create(payload, size);
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
		engine->destroy(this->instance);
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
	if (materials.contains(payload))
	{
		material = materials.at(payload);
	}
	else
	{
		material = filament::Material::Builder()
			.package(payload, size)
			.build(*engine);
		materials.insert({ payload, material });
	}

	instance = material->createInstance();
	instances.push_back(instance);
}

// material method

filament::Material::BlendingMode Material::getBlendingMode() const noexcept
{
	return material->getBlendingMode();
}

filament::Material::CullingMode Material::getCullingMode() const noexcept
{
	return material->getCullingMode();
}

filament::MaterialInstance const* Material::getDefaultInstance() const noexcept
{
	return material->getDefaultInstance();
}

filament::Material::Interpolation Material::getInterpolation() const noexcept
{
	return material->getInterpolation();
}

float Material::getMaskThreshold() const noexcept
{
	return material->getMaskThreshold();
}

filament::MaterialDomain Material::getMaterialDomain() const noexcept
{
	return material->getMaterialDomain();
}

char const* Material::getName() const noexcept
{
	return material->getName();
}

uint8_t Material::getParameterCount() const noexcept
{
	return material->getParameterCount();
}

size_t Material::getParameters(filament::Material::ParameterInfo* parameters, size_t count) const noexcept
{
	return material->getParameters(parameters, count);
}

filament::RefractionMode Material::getRefractionMode() const noexcept
{
	return material->getRefractionMode();
}

filament::RefractionType Material::getRefractionType() const noexcept
{
	return material->getRefractionType();
}

filament::AttributeBitset Material::getRequiredAttributes() const noexcept
{
	return material->getRequiredAttributes();
}

filament::Shading Material::getShading() const noexcept
{
	return material->getShading();
}

float Material::getSpecularAntiAliasingThreshold() const noexcept
{
	return material->getSpecularAntiAliasingThreshold();
}

float Material::getSpecularAntiAliasingVariance() const noexcept
{
	return material->getSpecularAntiAliasingVariance();
}

filament::TransparencyMode Material::getTransparencyMode() const noexcept
{
	return material->getTransparencyMode();
}

filament::VertexDomain Material::getVertexDomain() const noexcept
{
	return material->getVertexDomain();
}

bool Material::hasParameter(const char* name) const noexcept
{
	return material->hasParameter(name);
}

bool Material::hasShadowMultiplier()
{
	return material->hasShadowMultiplier();
}

bool Material::hasSpecularAntiAliasing() const noexcept
{
	return material->hasSpecularAntiAliasing();
}

bool Material::isColorWriteEnabled() const noexcept
{
	return material->isColorWriteEnabled();
}

bool Material::isDepthCullingEnabled()
{
	return material->isDepthCullingEnabled();
}

bool Material::isDepthWriteEnabled() const noexcept
{
	return material->isDepthWriteEnabled();
}

bool Material::isDoubleSided() const noexcept
{
	return material->isDoubleSided();
}

bool Material::isSampler(const char* name) const noexcept
{
	return material->isSampler(name);
}

template <typename T>
void Material::setDefaultParameter(const char* name, T value) noexcept
{
	return material->setDefaultParameter(name, value);
}

template void Material::setDefaultParameter<float>(const char* name, float value) noexcept;
template void Material::setDefaultParameter<int32_t>(const char* name, int32_t value) noexcept;
template void Material::setDefaultParameter<uint32_t>(const char* name, uint32_t value) noexcept;
template void Material::setDefaultParameter<int2>(const char* name, int2 value) noexcept;
template void Material::setDefaultParameter<int3>(const char* name, int3 value) noexcept;
template void Material::setDefaultParameter<int4>(const char* name, int4 value) noexcept;
template void Material::setDefaultParameter<uint2>(const char* name, uint2 value) noexcept;
template void Material::setDefaultParameter<uint3>(const char* name, uint3 value) noexcept;
template void Material::setDefaultParameter<uint4>(const char* name, uint4 value) noexcept;
template void Material::setDefaultParameter<float2>(const char* name, float2 value) noexcept;
template void Material::setDefaultParameter<float3>(const char* name, float3 value) noexcept;
template void Material::setDefaultParameter<float4>(const char* name, float4 value) noexcept;
template void Material::setDefaultParameter<mat3f>(const char* name, mat3f value) noexcept;
template void Material::setDefaultParameter<mat4f>(const char* name, mat4f value) noexcept;

void Material::setDefaultParameter(const char* name, filament::Texture const* texture,
	filament::TextureSampler const& sampler) noexcept
{
	return material->setDefaultParameter(name, texture, sampler);
}

void Material::setDefaultParameter(const char* name, filament::RgbType type, float3 color) noexcept
{
	return material->setDefaultParameter(name, type, color);
}

void Material::setDefaultParameter(const char* name, filament::RgbaType type, float4 color) noexcept
{
	return material->setDefaultParameter(name, type, color);
}

// instance

void Material::setColorWrite(bool enable) noexcept
{
	return instance->setColorWrite(enable);
}

void Material::setCullingMode(filament::MaterialInstance::CullingMode culling) noexcept
{
	return instance->setCullingMode(culling);
}

void Material::setDepthCulling(bool enable) noexcept
{
	return instance->setDepthCulling(enable);
}

void Material::setDepthWrite(bool enable) noexcept
{
	return instance->setDepthWrite(enable);
}

void Material::setDoubleSided(bool doubleSided) noexcept
{
	return instance->setDoubleSided(doubleSided);
}

void Material::setMaskThreshold(float threshold) noexcept
{
	return instance->setMaskThreshold(threshold);
}

template <typename T>
void Material::setParameter(const char* name, T value) noexcept
{
	return instance->setParameter(name, value);
}

template void Material::setParameter<float>(const char* name, float value) noexcept;
template void Material::setParameter<int32_t>(const char* name, int32_t value) noexcept;
template void Material::setParameter<uint32_t>(const char* name, uint32_t value) noexcept;
template void Material::setParameter<int2>(const char* name, int2 value) noexcept;
template void Material::setParameter<int3>(const char* name, int3 value) noexcept;
template void Material::setParameter<int4>(const char* name, int4 value) noexcept;
template void Material::setParameter<uint2>(const char* name, uint2 value) noexcept;
template void Material::setParameter<uint3>(const char* name, uint3 value) noexcept;
template void Material::setParameter<uint4>(const char* name, uint4 value) noexcept;
template void Material::setParameter<float2>(const char* name, float2 value) noexcept;
template void Material::setParameter<float3>(const char* name, float3 value) noexcept;
template void Material::setParameter<float4>(const char* name, float4 value) noexcept;
template void Material::setParameter<mat3f>(const char* name, mat3f value) noexcept;
template void Material::setParameter<mat4f>(const char* name, mat4f value) noexcept;

void Material::setParameter(const char* name, bool value) noexcept
{
	return instance->setParameter(name, value);
}

void Material::setParameter(const char* name, bool2 value) noexcept
{
	return instance->setParameter(name, value);
}

void Material::setParameter(const char* name, bool3 value) noexcept
{
	return instance->setParameter(name, value);
}

void Material::setParameter(const char* name, bool4 value) noexcept
{
	return instance->setParameter(name, value);
}

template <typename T>
void Material::setParameter(const char* name, T* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

template void Material::setParameter<float>(const char* name, float* value, size_t count) noexcept;
template void Material::setParameter<int32_t>(const char* name, int32_t* value, size_t count) noexcept;
template void Material::setParameter<uint32_t>(const char* name, uint32_t* value, size_t count) noexcept;
template void Material::setParameter<int2>(const char* name, int2* value, size_t count) noexcept;
template void Material::setParameter<int3>(const char* name, int3* value, size_t count) noexcept;
template void Material::setParameter<int4>(const char* name, int4* value, size_t count) noexcept;
template void Material::setParameter<uint2>(const char* name, uint2* value, size_t count) noexcept;
template void Material::setParameter<uint3>(const char* name, uint3* value, size_t count) noexcept;
template void Material::setParameter<uint4>(const char* name, uint4* value, size_t count) noexcept;
template void Material::setParameter<float2>(const char* name, float2* value, size_t count) noexcept;
template void Material::setParameter<float3>(const char* name, float3* value, size_t count) noexcept;
template void Material::setParameter<float4>(const char* name, float4* value, size_t count) noexcept;
template void Material::setParameter<mat4f>(const char* name, mat4f* value, size_t count) noexcept;

void Material::setParameter(const char* name, bool* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

void Material::setParameter(const char* name, bool2* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

void Material::setParameter(const char* name, bool3* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

void Material::setParameter(const char* name, bool4* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

template <>
void Material::setParameter<mat3f>(const char* name, mat3f* value, size_t count) noexcept
{
	return instance->setParameter(name, value, count);
}

void Material::setParameter(const char* name, filament::Texture const* texture,
	filament::TextureSampler const& sampler) noexcept
{
	return instance->setParameter(name, texture, sampler);
}

void Material::setParameter(const char* name, filament::RgbType type, filament::math::float3 color) noexcept
{
	return instance->setParameter(name, type, color);
}

void Material::setParameter(const char* name, filament::RgbaType type, filament::math::float4 color) noexcept
{
	return instance->setParameter(name, type, color);
}

void Material::setPolygonOffset(float scale, float constant) noexcept
{
	return instance->setPolygonOffset(scale, constant);
}

void Material::setScissor(uint32_t left, uint32_t bottom, uint32_t width, uint32_t height) noexcept
{
	return instance->setScissor(left, bottom, width, height);
}

void Material::setSpecularAntiAliasingThreshold(float threshold) noexcept
{
	return instance->setSpecularAntiAliasingThreshold(threshold);
}

void Material::setSpecularAntiAliasingVariance(float variance) noexcept
{
	return instance->setSpecularAntiAliasingVariance(variance);
}

void Material::setTransparencyMode(filament::MaterialInstance::TransparencyMode mode) noexcept
{
	return instance->setTransparencyMode(mode);
}

void Material::unsetScissor()
{
	return instance->unsetScissor();
}