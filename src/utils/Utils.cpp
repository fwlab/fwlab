#include <cmath>
#include "Utils.h"

namespace gl::utils
{
	float Utils::reflectanceToIOR(float reflectance)
	{
		return 2.0 / (1.0 - std::sqrt(reflectance)) - 1;
	}

	float Utils::iorToReflectance(float ior)
	{
		return std::pow(1.0 - 2.0 / (ior + 1.0), 2);
	}

	uint16_t Utils::getSize(filament::VertexBuffer::AttributeType type)
	{
		switch (type)
		{
		case filament::VertexBuffer::AttributeType::BYTE:
			return 1;
		case filament::VertexBuffer::AttributeType::BYTE2:
			return 2;
		case filament::VertexBuffer::AttributeType::BYTE3:
			return 3;
		case filament::VertexBuffer::AttributeType::BYTE4:
			return 4;
		case filament::VertexBuffer::AttributeType::FLOAT:
			return 4;
		case filament::VertexBuffer::AttributeType::FLOAT2:
			return 8;
		case filament::VertexBuffer::AttributeType::FLOAT3:
			return 12;
		case filament::VertexBuffer::AttributeType::FLOAT4:
			return 16;
		case filament::VertexBuffer::AttributeType::HALF:
			return 2;
		case filament::VertexBuffer::AttributeType::HALF2:
			return 4;
		case filament::VertexBuffer::AttributeType::HALF3:
			return 6;
		case filament::VertexBuffer::AttributeType::HALF4:
			return 8;
		case filament::VertexBuffer::AttributeType::INT:
			return 4;
		case filament::VertexBuffer::AttributeType::SHORT:
			return 2;
		case filament::VertexBuffer::AttributeType::SHORT2:
			return 4;
		case filament::VertexBuffer::AttributeType::SHORT3:
			return 6;
		case filament::VertexBuffer::AttributeType::SHORT4:
			return 8;
		case filament::VertexBuffer::AttributeType::UBYTE:
			return 1;
		case filament::VertexBuffer::AttributeType::UBYTE2:
			return 2;
		case filament::VertexBuffer::AttributeType::UBYTE3:
			return 3;
		case filament::VertexBuffer::AttributeType::UBYTE4:
			return 4;
		case filament::VertexBuffer::AttributeType::UINT:
			return 4;
		case filament::VertexBuffer::AttributeType::USHORT:
			return 2;
		case filament::VertexBuffer::AttributeType::USHORT2:
			return 4;
		case filament::VertexBuffer::AttributeType::USHORT3:
			return 6;
		case filament::VertexBuffer::AttributeType::USHORT4:
			return 8;
		default:
			throw "unknown vertex attribute type";
		}
	}

	uint16_t Utils::getSize(filament::IndexBuffer::IndexType type)
	{
		switch (type)
		{
		case filament::IndexBuffer::IndexType::USHORT:
			return 2;
		case filament::IndexBuffer::IndexType::UINT:
			return 4;
		default:
			throw "unknown index buffer type";
		}
	}
}