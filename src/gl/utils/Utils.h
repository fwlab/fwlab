#ifndef GL_UTILS_H
#define GL_UTILS_H
#include <stdint.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>

namespace gl::utils
{
	class Utils
	{
	public:
		static float reflectanceToIOR(float reflectance);
		static float iorToReflectance(float ior);
		static uint16_t getSize(filament::VertexBuffer::AttributeType type);
		static uint16_t getSize(filament::IndexBuffer::IndexType type);
	};
}

#endif