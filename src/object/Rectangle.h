#ifndef FWLAB_RECTANGLE_H
#define FWLAB_RECTANGLE_H
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// ¾ØÐÎ
/// </summary>
class Rectangle {
public:
	explicit Rectangle(Context* context, filament::Material* material);
	virtual ~Rectangle();
	filament::VertexBuffer* vertexBuffer;
	filament::IndexBuffer* indexBuffer;
	filament::Material* material;
	utils::Entity entity;

private:
	Context* context;
};

#endif