#ifndef FWLAB_CORE_BUFFER_ATTRIBUTE_H
#define FWLAB_CORE_BUFFER_ATTRIBUTE_H
#include <stdint.h>
#include <vector>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <math/vec3.h>

namespace fwlab::core
{
	class BufferAttribute
	{
	public:
		virtual ~BufferAttribute();
		void *getArray() const;
		void setArray(void *array);
		uint8_t getItemSize() const;
		void setItemSize(uint8_t itemSize);
		uint32_t getCount() const;
		void setCount(uint32_t count);

	protected:
		BufferAttribute() = default;
		template <typename T>
		BufferAttribute(T *array, uint8_t itemSize = 3, uint32_t count = 0);
		BufferAttribute(std::vector<filament::math::float2> vertices);
		BufferAttribute(std::vector<filament::math::float3> vertices);
		void *array = nullptr;
		uint8_t itemSize = 3;
		uint32_t count = 0;
	};

	class VertexBufferAttribute : public BufferAttribute
	{
	public:
		template <typename T>
		VertexBufferAttribute(
			T *array,
			uint8_t itemSize = 3,
			uint32_t count = 0,
			filament::VertexBuffer::AttributeType attributeType = filament::VertexBuffer::AttributeType::FLOAT3,
			bool normalized = false);
		VertexBufferAttribute(
			std::vector<filament::math::float2> vertices,
			bool normalized = false);
		VertexBufferAttribute(
			std::vector<filament::math::float3> vertices,
			bool normalized = false);
		virtual ~VertexBufferAttribute();
		filament::VertexBuffer::AttributeType getAttributeType() const;
		void setAttributeType(filament::VertexBuffer::AttributeType attributeType);
		bool isNormalized() const;
		void setNormalized(bool normalized);

	protected:
		filament::VertexBuffer::AttributeType attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
		bool normalized = false;
	};

	class IndexBufferAttribute : public BufferAttribute
	{
	public:
		template <typename T>
		IndexBufferAttribute(
			T *array,
			uint32_t count = 0,
			filament::IndexBuffer::IndexType indexType = filament::IndexBuffer::IndexType::UINT);
		IndexBufferAttribute(std::vector<uint16_t> vertices);
		IndexBufferAttribute(std::vector<uint32_t> vertices);
		IndexBufferAttribute(std::vector<filament::math::uint3> triangles);
		virtual ~IndexBufferAttribute();
		filament::IndexBuffer::IndexType getIndexType() const;
		void setIndexType(filament::IndexBuffer::IndexType indexType);

	protected:
		filament::IndexBuffer::IndexType indexType = filament::IndexBuffer::IndexType::UINT;
	};
}

#endif