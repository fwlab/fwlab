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
		Mesh(core::BufferGeometry *geometry, material::Material *material);
		virtual ~Mesh();
		bool getCulling() const;
		void setCulling(bool culling);
		bool getCastShadows() const;
		void setCastShadows(bool castShadows);
		bool getReceiveShadows() const;
		void setReceiveShadows(bool receiveShadows);
		core::BufferGeometry *getGeometry() const;
		void setGeometry(core::BufferGeometry *geometry);
		material::Material *getMaterial() const;
		void setMaterial(material::Material *material);

		// RenderableManager
		filament::Box getAxisAlignedBoundingBox() const;
		filament::AttributeBitset getEnabledAttributesAt(uint8_t level, size_t primitiveIndex) const;
		uint8_t getLayerMask() const;
		bool getLightChannel(unsigned int channel) const;
		filament::MaterialInstance *getMaterialInstanceAt(size_t primitiveIndex) const;
		size_t getPrimitiveCount() const;
		bool isShadowCaster() const;
		bool isShadowReceiver() const;
		void setAxisAlignedBoundingBox(const filament::Box &aabb);
		void setBlendOrderAt(size_t primitiveIndex, uint16_t order);
		void setBones(filament::RenderableManager::Bone *transforms, size_t boneCount, size_t offset);
		void setBones(filament::math::mat4f *transforms, size_t boneCount, size_t offset);
		void setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type,
						   filament::VertexBuffer *vertices, filament::IndexBuffer *indices,
						   size_t offset, size_t count);
		void setGeometryAt(size_t primitiveIndex, filament::RenderableManager::PrimitiveType type, size_t offset, size_t count);
		void setLayerMask(uint8_t select, uint8_t values);
		void setLightChannel(unsigned int channel, bool enable);
		void setMaterialInstanceAt(size_t primitiveIndex, filament::MaterialInstance *materialInstance);
		void setMorphWeights(filament::math::float4 &weights);
		void setPriority(uint8_t priority);
		void setScreenSpaceContactShadows(bool enable);
		void setSkinningBuffer(filament::SkinningBuffer *skinningBuffer, size_t count, size_t offset);

	protected:
		bool culling = true;
		bool castShadows = false;
		bool receiveShadows = false;
		core::BufferGeometry *geometry = nullptr;
		material::Material *material = nullptr;
	};
}

#endif