#include <utils/EntityManager.h>
#include <filament/LightManager.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>
#include "Mesh.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;
using namespace gl::material;
using namespace gl::object;

Mesh::Mesh()
{
}

Mesh::Mesh(BufferGeometry *geometry, Material *material)
{
	this->geometry = geometry;
	this->material = material;

	entity = utils::EntityManager::get().create();
	filament::RenderableManager::Builder(1)
		.boundingBox(*geometry->getBoundingBox())
		.geometry(0, material->getPrimitiveType(), geometry->getVertexBuffer(), geometry->getIndexBuffer())
		.material(0, material->getInstance())
		.culling(culling)
		.castShadows(castShadows)
		.receiveShadows(receiveShadows)
		.build(*engine, entity);
}

Mesh::~Mesh()
{
	if (geometry)
	{
		delete geometry;
		geometry = nullptr;
	}
	if (material)
	{
		material->dispose();
		material = nullptr;
	}
}

bool Mesh::getCulling() const noexcept
{
	return culling;
}

void Mesh::setCulling(bool culling) noexcept
{
	this->culling = culling;
	auto &manager = engine->getRenderableManager();
	manager.setCulling(manager.getInstance(entity), culling);
}

bool Mesh::getCastShadows() const noexcept
{
	return castShadows;
}

void Mesh::setCastShadows(bool castShadows) noexcept
{
	this->castShadows = castShadows;
	auto &manager = engine->getRenderableManager();
	manager.setCastShadows(manager.getInstance(entity), castShadows);
}

bool Mesh::getReceiveShadows() const noexcept
{
	return receiveShadows;
}

void Mesh::setReceiveShadows(bool receiveShadows) noexcept
{
	this->receiveShadows = receiveShadows;
	auto &manager = engine->getRenderableManager();
	manager.setReceiveShadows(manager.getInstance(entity), receiveShadows);
}

gl::core::BufferGeometry *Mesh::getGeometry() const noexcept
{
	return geometry;
}

void Mesh::setGeometry(gl::core::BufferGeometry *geometry) noexcept
{
	this->geometry = geometry;
}

gl::material::Material *Mesh::getMaterial() const noexcept
{
	return material;
}

void Mesh::setMaterial(gl::material::Material *material) noexcept
{
	this->material = material;
}

// RenderableManager

filament::Box Mesh::getAxisAlignedBoundingBox() const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getAxisAlignedBoundingBox(manager.getInstance(entity));
}

filament::AttributeBitset Mesh::getEnabledAttributesAt(uint8_t level, size_t primitiveIndex) const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getEnabledAttributesAt(manager.getInstance(entity), primitiveIndex);
}

uint8_t Mesh::getLayerMask() const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getLayerMask(manager.getInstance(entity));
}

bool Mesh::getLightChannel(unsigned int channel) const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getLightChannel(manager.getInstance(entity), channel);
}

filament::MaterialInstance *Mesh::getMaterialInstanceAt(size_t primitiveIndex) const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getMaterialInstanceAt(manager.getInstance(entity), primitiveIndex);
}

size_t Mesh::getPrimitiveCount() const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.getPrimitiveCount(manager.getInstance(entity));
}

bool Mesh::isShadowCaster() const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.isShadowCaster(manager.getInstance(entity));
}

bool Mesh::isShadowReceiver() const noexcept
{
	auto &manager = engine->getRenderableManager();
	return manager.isShadowReceiver(manager.getInstance(entity));
}

void Mesh::setAxisAlignedBoundingBox(const filament::Box &aabb) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setAxisAlignedBoundingBox(manager.getInstance(entity), aabb);
}

void Mesh::setBlendOrderAt(size_t primitiveIndex, uint16_t order) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setBlendOrderAt(manager.getInstance(entity), primitiveIndex, order);
}

void Mesh::setBones(filament::RenderableManager::Bone *transforms, size_t boneCount, size_t offset) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setBones(manager.getInstance(entity), transforms, boneCount, offset);
}

void Mesh::setBones(filament::math::mat4f *transforms, size_t boneCount, size_t offset) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setBones(manager.getInstance(entity), transforms, boneCount, offset);
}

void Mesh::setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type,
						 filament::VertexBuffer *vertices, filament::IndexBuffer *indices,
						 size_t offset, size_t count) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setGeometryAt(manager.getInstance(entity), primitiveIndex, type, vertices, indices, offset, count);
}

void Mesh::setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type, size_t offset, size_t count) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setGeometryAt(manager.getInstance(entity), primitiveIndex, type, offset, count);
}

void Mesh::setLayerMask(uint8_t select, uint8_t values) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setLayerMask(manager.getInstance(entity), select, values);
}

void Mesh::setLightChannel(unsigned int channel, bool enable) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setLightChannel(manager.getInstance(entity), channel, enable);
}

void Mesh::setMaterialInstanceAt(size_t primitiveIndex, filament::MaterialInstance *materialInstance) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setMaterialInstanceAt(manager.getInstance(entity), primitiveIndex, materialInstance);
}

void Mesh::setMorphWeights(filament::math::float4 &weights) noexcept
{
	//auto &manager = engine->getRenderableManager();
	//manager.setMorphWeights(manager.getInstance(entity), weights);
}

void Mesh::setPriority(uint8_t priority) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setPriority(manager.getInstance(entity), priority);
}

void Mesh::setScreenSpaceContactShadows(bool enable) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setScreenSpaceContactShadows(manager.getInstance(entity), enable);
}

void Mesh::setSkinningBuffer(filament::SkinningBuffer *skinningBuffer, size_t count, size_t offset) noexcept
{
	auto &manager = engine->getRenderableManager();
	manager.setSkinningBuffer(manager.getInstance(entity), skinningBuffer, count, offset);
}