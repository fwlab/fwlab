#include <filament/RenderableManager.h>
#include "PointsMaterial.h"

using namespace gl::material;

PointsMaterial::PointsMaterial(Context* context) : Material(context)
{
	this->primitiveType = filament::RenderableManager::PrimitiveType::POINTS;
}

PointsMaterial::~PointsMaterial()
{

}