#ifndef fWLAB_OBJECT_TRIANGLE_H
#define fWLAB_OBJECT_TRIANGLE_H
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// Èý½ÇÐÎ
/// </summary>
class Triangle {
public:
	explicit Triangle(Context* context, filament::Material* material);
	virtual ~Triangle();
	filament::VertexBuffer* vertexBuffer;
	filament::IndexBuffer* indexBuffer;
	filament::Material* material;
	utils::Entity entity;

private:
	Context* context;
};

#endif