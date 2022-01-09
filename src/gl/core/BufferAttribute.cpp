#include <algorithm>
#include "BufferAttribute.h"

using namespace gl::core;

// BufferAttribute

BufferAttribute::BufferAttribute(void* array, uint8_t itemSize, uint32_t count)
{
	assert(itemSize > 0);
	this->array = array;
	this->itemSize = itemSize;
	this->count = count;
}

BufferAttribute::BufferAttribute(std::vector<filament::math::float2> vertices)
{
	itemSize = 2;
	count = vertices.size();
	array = new float[itemSize * count];
	std::copy(vertices.begin(), vertices.end(), static_cast<filament::math::float2*>(array));
}

BufferAttribute::BufferAttribute(std::vector<filament::math::float3> vertices)
{
	itemSize = 3;
	count = vertices.size();
	array = new float[itemSize * count];
	std::copy(vertices.begin(), vertices.end(), static_cast<filament::math::float3*>(array));
}

BufferAttribute::~BufferAttribute()
{
	// 由于不知道array的大小，无法删除array
	//if (array != nullptr) {
	//	delete[] array;
	//	array = nullptr;
	//}
	//count = 0;
}

void* BufferAttribute::getArray() const noexcept
{
	return array;
}

void BufferAttribute::setArray(void* array) noexcept
{
	if (this->array)
	{
		delete[] this->array;
	}
	this->array = array;
}

uint8_t BufferAttribute::getItemSize() const noexcept
{
	return itemSize;
}

void BufferAttribute::setItemSize(uint8_t itemSize) noexcept
{
	this->itemSize = itemSize;
}

uint32_t BufferAttribute::getCount() const noexcept
{
	return count;
}

void BufferAttribute::setCount(uint32_t count) noexcept
{
	this->count = count;
}

// VertexBufferAttribute

VertexBufferAttribute::VertexBufferAttribute(
	void* array, uint8_t itemSize,
	uint32_t count,
	filament::VertexBuffer::AttributeType attributeType,
	bool normalized
) : BufferAttribute(array, itemSize, count)
{
	this->attributeType = attributeType;
	this->normalized = normalized;
}

VertexBufferAttribute::VertexBufferAttribute(std::vector<filament::math::float2> vertices, bool normalized) :
	BufferAttribute(vertices)
{
	attributeType = filament::VertexBuffer::AttributeType::FLOAT2;
	this->normalized = normalized;
}

VertexBufferAttribute::VertexBufferAttribute(std::vector<filament::math::float3> vertices, bool normalized) :
	BufferAttribute(vertices)
{
	attributeType = filament::VertexBuffer::AttributeType::FLOAT3;
	this->normalized = normalized;
}

VertexBufferAttribute::~VertexBufferAttribute()
{
	if (array != nullptr)
	{
		if (attributeType == filament::VertexBuffer::AttributeType::FLOAT2 ||
			attributeType == filament::VertexBuffer::AttributeType::FLOAT3)
		{
			delete[] static_cast<float*>(array);
			count = 0;
		}
		else if (attributeType == filament::VertexBuffer::AttributeType::SHORT4)
		{
			delete[] static_cast<uint16_t*>(array);
			count = 0;
		}
		else
		{
			throw "VertexBufferAttribute::~VertexBufferAttribute: not implemented";
		}
	}
}

filament::VertexBuffer::AttributeType VertexBufferAttribute::getAttributeType() const noexcept
{
	return attributeType;
}

void VertexBufferAttribute::setAttributeType(filament::VertexBuffer::AttributeType attributeType) noexcept
{
	this->attributeType = attributeType;
}

bool VertexBufferAttribute::isNormalized() const noexcept
{
	return normalized;
}

void VertexBufferAttribute::setNormalized(bool normalized) noexcept
{
	this->normalized = normalized;
}

// IndexBufferAttribute

IndexBufferAttribute::IndexBufferAttribute(void* array, uint32_t count, filament::IndexBuffer::IndexType indexType) :
	BufferAttribute(array, 1, count)
{
	this->indexType = indexType;
}

IndexBufferAttribute::IndexBufferAttribute(std::vector<uint16_t> vertices)
{
	itemSize = 1;
	count = vertices.size();
	array = new float[itemSize * count];
	std::copy(vertices.begin(), vertices.end(), static_cast<uint16_t*>(array));

	indexType = filament::IndexBuffer::IndexType::USHORT;
}

IndexBufferAttribute::IndexBufferAttribute(std::vector<uint32_t> vertices)
{
	itemSize = 1;
	count = vertices.size();
	array = new float[itemSize * count];
	std::copy(vertices.begin(), vertices.end(), static_cast<uint32_t*>(array));

	indexType = filament::IndexBuffer::IndexType::UINT;
}

IndexBufferAttribute::IndexBufferAttribute(std::vector<filament::math::uint3> triangles)
{
	itemSize = 1;
	count = triangles.size() * 3;
	array = new float[itemSize * count];
	std::copy(triangles.begin(), triangles.end(), static_cast<filament::math::uint3*>(array));

	indexType = filament::IndexBuffer::IndexType::UINT;
}

IndexBufferAttribute::~IndexBufferAttribute()
{
	if (array != nullptr)
	{
		if (indexType == filament::IndexBuffer::IndexType::USHORT)
		{
			delete[] static_cast<uint16_t*>(array);
			count = 0;
		}
		else // UINT
		{
			delete[] static_cast<uint32_t*>(array);
		}
	}
}

filament::IndexBuffer::IndexType IndexBufferAttribute::getIndexType() const noexcept
{
	return indexType;
}

void IndexBufferAttribute::setIndexType(filament::IndexBuffer::IndexType indexType) noexcept
{
	this->indexType = indexType;
}