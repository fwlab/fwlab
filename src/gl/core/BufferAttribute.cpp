#include "BufferAttribute.h"

using namespace gl::core;

BufferAttribute::BufferAttribute(void* array, uint8_t itemSize)
{
	this->array = array;
	this->itemSize = itemSize;
}

BufferAttribute::~BufferAttribute()
{
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

VertexBufferAttribute::VertexBufferAttribute(void* array, uint8_t itemSize, bool normalized) : BufferAttribute(array, itemSize)
{
	this->normalized = normalized;
}

IndexBufferAttribute::IndexBufferAttribute(void* array, uint8_t itemSize) : BufferAttribute(array, itemSize)
{

}
