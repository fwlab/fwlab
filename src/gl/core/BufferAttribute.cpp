#include "BufferAttribute.h"

template <typename T>
BufferAttribute<T>::BufferAttribute(Context* context)
{
	this->context = context;
}

template <typename T>
BufferAttribute<T>::~BufferAttribute()
{
	if (array != nullptr) {
		delete[] array;
	}
}

template class BufferAttribute<float>;
template class BufferAttribute<double>;
template class BufferAttribute<uint16_t>;
template class BufferAttribute<uint32_t>;

VertexBufferAttribute::VertexBufferAttribute(Context* context) : BufferAttribute(context)
{

}

IndexBufferAttribute::IndexBufferAttribute(Context* context) : BufferAttribute(context)
{

}