#include <filament/TransformManager.h>
#include "Object3D.h"

Object3D::Object3D(Context* context)
{
	this->context = context;

	filament::TransformManager& manager = context->engine->getTransformManager();
	manager.setAccurateTranslationsEnabled(true);
}

Object3D::~Object3D()
{
	if (context && context->engine && entity)
	{
		context->engine->destroy(entity);
	}
}

Object3D* Object3D::create()
{
	return this;
}

filament::math::mat4 Object3D::getTransform()
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.getTransformAccurate(manager.getInstance(entity));
}

filament::math::mat4 Object3D::getWorldTransform()
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.getWorldTransformAccurate(manager.getInstance(entity));
}

void Object3D::setTransform(filament::math::mat4 transform)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.setTransform(manager.getInstance(entity), transform);
}

void Object3D::setTranslation(filament::math::double3 translation)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.setTransform(manager.getInstance(entity), filament::math::mat4::translation(translation));
}

void Object3D::setRotation(double radian, filament::math::double3 axis)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.setTransform(manager.getInstance(entity), filament::math::mat4::rotation(radian, axis));
}

void Object3D::setScaling(filament::math::double3 scaling)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	return manager.setTransform(manager.getInstance(entity), filament::math::mat4::scaling(scaling));
}