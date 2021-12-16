#include <climits>
#include "Geometry.h"

Geometry::Geometry(Context* context)
{
	this->context = context;
}

Geometry::~Geometry()
{
	if (context && context->engine)
	{
		if (vertexBuffer)
		{
			context->engine->destroy(vertexBuffer);
		}
		if (indexBuffer)
		{
			context->engine->destroy(indexBuffer);
		}
	}
	if (boundingBox)
	{
		auto min = boundingBox->getMin();
		auto max = boundingBox->getMax();
		delete& min;
		delete& max;
		delete boundingBox;
	}
}

void Geometry::create()
{

}

void Geometry::computeBoundingBox(float vertices[], uint32_t verticesSize)
{
	auto* min = new filament::math::float3(FLT_MAX, FLT_MAX, FLT_MAX);
	auto* max = new filament::math::float3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

	for (uint32_t i = 0, len = verticesSize / 3; i < len; i++)
	{
		auto x = vertices[i * 3];
		auto y = vertices[i * 3 + 1];
		auto z = vertices[i * 3 + 2];
		if (x < min->x)
		{
			min->x = x;
		}
		if (y < min->y)
		{
			min->y = y;
		}
		if (z < min->z)
		{
			min->z = z;
		}
		if (x > max->x)
		{
			max->x = x;
		}
		if (y > max->y)
		{
			max->y = y;
		}
		if (z > max->z)
		{
			max->z = z;
		}
	}

	// 顶点为空的情况
	if (min->x > max->x)
	{
		min->x = max->x = 0;
	}
	if (min->y > max->y)
	{
		min->y = max->y = 0;
	}
	if (min->z > max->z)
	{
		min->z = max->z = 0;
	}

	// 只有一个顶点的情况
	if (min->x == max->x)
	{
		min->x -= 1;
		max->x += 1;
	}
	if (min->y == max->y)
	{
		min->x -= 1;
		max->x += 1;
	}
	if (min->z == max->z)
	{
		min->x -= 1;
		max->x += 1;
	}

	boundingBox = new filament::Box();
	boundingBox->set(*min, *max);
}