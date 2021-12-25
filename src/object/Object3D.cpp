#include <filament/TransformManager.h>
#include "Object3D.h"

Object3D::Object3D(Context* context)
{
	this->context = context;

	translateMatrix = new filament::math::mat4();
	rotateMatrix = new filament::math::mat4();
	scaleMatrix = new filament::math::mat4();
	matrix = new filament::math::mat4();
	this->updateMatrix();

	filament::TransformManager& manager = context->engine->getTransformManager();
	manager.setAccurateTranslationsEnabled(true);
}

Object3D::~Object3D()
{
	if (context && context->engine && entity)
	{
		context->engine->destroy(entity);
	}
	delete translateMatrix;
	delete rotateMatrix;
	delete scaleMatrix;
	delete matrix;
}

void Object3D::create()
{

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
	*translateMatrix = filament::math::mat4::translation(translation);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::setRotation(double radian, filament::math::double3 axis)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	*rotateMatrix = filament::math::mat4::rotation(radian, axis);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::setScaling(filament::math::double3 scaling)
{
	filament::TransformManager& manager = context->engine->getTransformManager();
	*scaleMatrix = filament::math::mat4::scaling(scaling);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::updateMatrix()
{
	auto worldMatrix = getWorldTransform();
	*matrix = (*translateMatrix) * (*rotateMatrix) * (*scaleMatrix);
}