#include <filament/RenderableManager.h>
#include "PointsMaterial.h"

PointsMaterial::PointsMaterial(Context* context) : Material(context)
{
	this->primitiveType = filament::RenderableManager::PrimitiveType::POINTS;
}

PointsMaterial::~PointsMaterial()
{

}