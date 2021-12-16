#ifndef FWLAB_POINT_H
#define FWLAB_POINT_H
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// µã
/// </summary>
class Point {
public:
	explicit Point(Context* context, filament::Material* material);
	virtual ~Point();
	filament::VertexBuffer* vertexBuffer;
	filament::IndexBuffer* indexBuffer;
	filament::Material* material;
	utils::Entity entity;

private:
	Context* context;
};

#endif