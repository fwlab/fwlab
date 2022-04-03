#ifndef FWLAB_CORE_BUFFER_VECTOR_H
#define FWLAB_CORE_BUFFER_VECTOR_H
#include <vector>

namespace fwlab::core
{
	template <typename T>
	class BufferVector
	{
	public:
		std::vector<T>& getRead() { return vectors[readIndex]; }
		std::vector<T>& getWrite() { return vectors[1 - readIndex]; }
		void swap() { readIndex = 1 - readIndex; }

	private:
		std::vector<T> vectors[2];
		int readIndex = 0;
	};
}

#endif