#include "BufferAttribute.h"

using namespace gl::core;

template <typename T>
BufferAttribute<T>::~BufferAttribute()
{
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

template class BufferAttribute<float>;
template class BufferAttribute<double>;
template class BufferAttribute<uint16_t>;
template class BufferAttribute<uint32_t>;
