#include <filament/RenderableManager.h>
#include "LineBasicMaterial.h"

using namespace gl::material;

LineBasicMaterial::LineBasicMaterial(Context* context) : Material(context)
{
	this->primitiveType = filament::RenderableManager::PrimitiveType::LINES;
}

LineBasicMaterial::~LineBasicMaterial()
{

}