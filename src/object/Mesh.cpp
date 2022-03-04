#include <utils/EntityManager.h>
#include <filament/LightManager.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>
#include "Mesh.h"
#include "../context/context.h"

namespace fwlab::object
{
	Mesh::Mesh()
	{
	}

	Mesh::Mesh(core::BufferGeometry *geometry, material::Material *material)
	{
		this->geometry = geometry;
		this->material = material;

		auto engine = app->getEngine();

		entity = ::utils::EntityManager::get().create();
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

	bool Mesh::getCulling() const
	{
		return culling;
	}

	void Mesh::setCulling(bool culling)
	{
		this->culling = culling;
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setCulling(manager.getInstance(entity), culling);
	}

	bool Mesh::getCastShadows() const
	{
		return castShadows;
	}

	void Mesh::setCastShadows(bool castShadows)
	{
		this->castShadows = castShadows;
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setCastShadows(manager.getInstance(entity), castShadows);
	}

	bool Mesh::getReceiveShadows() const
	{
		return receiveShadows;
	}

	void Mesh::setReceiveShadows(bool receiveShadows)
	{
		this->receiveShadows = receiveShadows;
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setReceiveShadows(manager.getInstance(entity), receiveShadows);
	}

	core::BufferGeometry *Mesh::getGeometry() const
	{
		return geometry;
	}

	void Mesh::setGeometry(core::BufferGeometry *geometry)
	{
		this->geometry = geometry;
	}

	material::Material *Mesh::getMaterial() const
	{
		return material;
	}

	void Mesh::setMaterial(material::Material *material)
	{
		this->material = material;
	}

	// RenderableManager

	filament::Box Mesh::getAxisAlignedBoundingBox() const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getAxisAlignedBoundingBox(manager.getInstance(entity));
	}

	filament::AttributeBitset Mesh::getEnabledAttributesAt(uint8_t level, size_t primitiveIndex) const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getEnabledAttributesAt(manager.getInstance(entity), primitiveIndex);
	}

	uint8_t Mesh::getLayerMask() const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getLayerMask(manager.getInstance(entity));
	}

	bool Mesh::getLightChannel(unsigned int channel) const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getLightChannel(manager.getInstance(entity), channel);
	}

	filament::MaterialInstance *Mesh::getMaterialInstanceAt(size_t primitiveIndex) const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getMaterialInstanceAt(manager.getInstance(entity), primitiveIndex);
	}

	size_t Mesh::getPrimitiveCount() const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.getPrimitiveCount(manager.getInstance(entity));
	}

	bool Mesh::isShadowCaster() const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.isShadowCaster(manager.getInstance(entity));
	}

	bool Mesh::isShadowReceiver() const
	{
		auto &manager = app->getEngine()->getRenderableManager();
		return manager.isShadowReceiver(manager.getInstance(entity));
	}

	void Mesh::setAxisAlignedBoundingBox(const filament::Box &aabb)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setAxisAlignedBoundingBox(manager.getInstance(entity), aabb);
	}

	void Mesh::setBlendOrderAt(size_t primitiveIndex, uint16_t order)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setBlendOrderAt(manager.getInstance(entity), primitiveIndex, order);
	}

	void Mesh::setBones(filament::RenderableManager::Bone *transforms, size_t boneCount, size_t offset)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setBones(manager.getInstance(entity), transforms, boneCount, offset);
	}

	void Mesh::setBones(filament::math::mat4f *transforms, size_t boneCount, size_t offset)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setBones(manager.getInstance(entity), transforms, boneCount, offset);
	}

	void Mesh::setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type,
							 filament::VertexBuffer *vertices, filament::IndexBuffer *indices,
							 size_t offset, size_t count)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setGeometryAt(manager.getInstance(entity), primitiveIndex, type, vertices, indices, offset, count);
	}

	void Mesh::setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type, size_t offset, size_t count)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setGeometryAt(manager.getInstance(entity), primitiveIndex, type, offset, count);
	}

	void Mesh::setLayerMask(uint8_t select, uint8_t values)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setLayerMask(manager.getInstance(entity), select, values);
	}

	void Mesh::setLightChannel(unsigned int channel, bool enable)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setLightChannel(manager.getInstance(entity), channel, enable);
	}

	void Mesh::setMaterialInstanceAt(size_t primitiveIndex, filament::MaterialInstance *materialInstance)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setMaterialInstanceAt(manager.getInstance(entity), primitiveIndex, materialInstance);
	}

	void Mesh::setMorphWeights(filament::math::float4 &weights)
	{
		// auto &manager = engine->getRenderableManager();
		// manager.setMorphWeights(manager.getInstance(entity), weights);
	}

	void Mesh::setPriority(uint8_t priority)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setPriority(manager.getInstance(entity), priority);
	}

	void Mesh::setScreenSpaceContactShadows(bool enable)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setScreenSpaceContactShadows(manager.getInstance(entity), enable);
	}

	void Mesh::setSkinningBuffer(filament::SkinningBuffer *skinningBuffer, size_t count, size_t offset)
	{
		auto &manager = app->getEngine()->getRenderableManager();
		manager.setSkinningBuffer(manager.getInstance(entity), skinningBuffer, count, offset);
	}
}