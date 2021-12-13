#ifndef fWLAB_SCENE_OBJECT_H
#define fWLAB_SCENE_OBJECT_H
#include <filament/Engine.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Material.h>
#include <utils/Entity.h>

/// <summary>
/// Èý½ÇÐÎ
/// </summary>
class Triangle {
public:
	explicit Triangle(filament::Engine* engine, filament::Material* material);
	virtual ~Triangle();
	filament::VertexBuffer* vertexBuffer;
	filament::IndexBuffer* indexBuffer;
	filament::Material* material;
	utils::Entity entity;

private:
	filament::Engine* engine;
};

#endif