#include <algorithm>
#include "resources/resources.h"
#include "Material.h"
#include "../context/context.h"

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

void Material::setDefaultParameter(const char* name, filament::Texture const* texture,
	filament::TextureSampler const& sampler) noexcept
{
	return material->setDefaultParameter(name, texture, sampler);
}