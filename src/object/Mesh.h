#ifndef FWLAB_OBJECT_MESH_H
#define FWLAB_OBJECT_MESH_H
#include <filament/RenderableManager.h>
#include <utils/Entity.h>
#include "../core/BufferGeometry.h"
#include "../material/Material.h"
#include "../core/Object3D.h"

namespace fwlab::object
{
	class Mesh : public core::Object3D
	{
	public:
		Mesh();
		Mesh(core::BufferGeometry* geometry, material::Material* material);
		virtual ~Mesh();
		bool getCulling() const noexcept;
		void setCulling(bool culling) noexcept;
		bool getCastShadows() const noexcept;
		void setCastShadows(bool castShadows) noexcept;
		bool getReceiveShadows() const noexcept;
		void setReceiveShadows(bool receiveShadows) noexcept;
		core::BufferGeometry* getGeometry() const noexcept;
		void setGeometry(core::BufferGeometry* geometry) noexcept;
		material::Material* getMaterial() const noexcept;
		void setMaterial(material::Material* material) noexcept;

		// RenderableManager
		filament::Box getAxisAlignedBoundingBox() const noexcept;
		filament::AttributeBitset getEnabledAttributesAt(uint8_t level, size_t primitiveIndex) const noexcept;
		uint8_t getLayerMask() const noexcept;
		bool getLightChannel(unsigned int channel) const noexcept;
		filament::MaterialInstance* getMaterialInstanceAt(size_t primitiveIndex) const noexcept;
		size_t getPrimitiveCount() const noexcept;
		bool isShadowCaster() const noexcept;
		bool isShadowReceiver() const noexcept;
		void setAxisAlignedBoundingBox(const filament::Box& aabb) noexcept;
		void setBlendOrderAt(size_t primitiveIndex, uint16_t order) noexcept;
		void setBones(filament::RenderableManager::Bone* transforms, size_t boneCount, size_t offset) noexcept;
		void setBones(filament::math::mat4f* transforms, size_t boneCount, size_t offset) noexcept;
		void setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type,
			filament::VertexBuffer* vertices, filament::IndexBuffer* indices,
			size_t offset, size_t count) noexcept;
		void setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type, size_t offset, size_t count) noexcept;
		void setLayerMask(uint8_t select, uint8_t values) noexcept;
		void setLightChannel(unsigned int channel, bool enable) noexcept;
		void setMaterialInstanceAt(size_t primitiveIndex, filament::MaterialInstance* materialInstance) noexcept;
		void setMorphWeights(filament::math::float4& weights) noexcept;
		void setPriority(uint8_t priority) noexcept;
		void setScreenSpaceContactShadows(bool enable) noexcept;
		void setSkinningBuffer(filament::SkinningBuffer* skinningBuffer, size_t count, size_t offset) noexcept;

	protected:
		bool culling = true;
		bool castShadows = false;
		bool receiveShadows = false;
		core::BufferGeometry* geometry = nullptr;
		material::Material* material = nullptr;
	};
}

#endif