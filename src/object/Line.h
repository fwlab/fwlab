#ifndef FWLAB_LINE_H
#define FWLAB_LINE_H
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// Ïß
/// </summary>
class Line {
public:
	explicit Line(Context* context, filament::Material* material);
	virtual ~Line();
	filament::VertexBuffer* vertexBuffer;
	filament::IndexBuffer* indexBuffer;
	filament::Material* material;
	utils::Entity entity;

private:
	Context* context;
};

#endif