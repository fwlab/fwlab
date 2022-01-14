#include <filament/TransformManager.h>
#include "../math/mat4.h"
#include "Object3D.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;

Object3D::Object3D()
{
	auto& manager = engine->getTransformManager();
	manager.setAccurateTranslationsEnabled(true);
}

Object3D::~Object3D()
{
	engine->destroy(entity);
}

utils::Entity Object3D::getEntity() const noexcept
{
	return entity;
}

void Object3D::setEntity(utils::Entity entity) noexcept
{
	if (this->entity)
	{
		engine->destroy(this->entity);
	}
	this->entity = entity;
}

filament::math::double3 Object3D::getPosition() const noexcept
{
	return position;
}

void Object3D::setPosition(filament::math::double3 position) noexcept
{
	this->position = position;
	updateMatrix();
}

filament::math::quat Object3D::getRotation() const noexcept
{
	return rotation;
}

void Object3D::setRotation(filament::math::quat rotation) noexcept
{
	this->rotation = rotation;
	updateMatrix();
}

void Object3D::setRotation(filament::math::double3 axis, double angle) noexcept
{
	this->rotation = filament::math::quat::fromAxisAngle(axis, angle);
	updateMatrix();
}

filament::math::double3 Object3D::getScale() const noexcept
{
	return scale;
}

void Object3D::setScale(filament::math::double3 scale) noexcept
{
	this->scale = scale;
	updateMatrix();
}

filament::math::mat4 Object3D::getMatrix() const noexcept
{
	auto& manager = engine->getTransformManager();
	return manager.getTransformAccurate(manager.getInstance(entity));
}

void Object3D::setMatrix(filament::math::mat4 matrix) noexcept
{
	this->matrix = matrix;
	auto& manager = engine->getTransformManager();
	manager.setTransform(manager.getInstance(entity), matrix);
}

filament::math::mat4 Object3D::getMatrixWorld() const noexcept
{
	filament::TransformManager& manager = engine->getTransformManager();
	return manager.getWorldTransformAccurate(manager.getInstance(entity));
}

void Object3D::updateMatrix()
{
	matrix = gl::math::compose(position, rotation, scale);
	auto& manager = engine->getTransformManager();
	manager.setTransform(manager.getInstance(entity), matrix);
}