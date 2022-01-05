#include <filament/RenderableManager.h>
#include "LineBasicMaterial.h"

using namespace gl::material;

LineBasicMaterial::LineBasicMaterial()
{
	this->primitiveType = filament::RenderableManager::PrimitiveType::LINES;
}

LineBasicMaterial::~LineBasicMaterial()
{

}