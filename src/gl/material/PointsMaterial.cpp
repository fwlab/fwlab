#include <filament/RenderableManager.h>
#include "PointsMaterial.h"

using namespace gl::material;

PointsMaterial::PointsMaterial()
{
	this->primitiveType = filament::RenderableManager::PrimitiveType::POINTS;
}

PointsMaterial::~PointsMaterial()
{

}