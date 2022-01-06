#include <filament/TransformManager.h>
#include "Object3D.h"
#include "../context/context.h"

using namespace gl::context;
using namespace gl::core;

Object3D::Object3D()
{
	translateMatrix = new filament::math::mat4();
	rotateMatrix = new filament::math::mat4();
	scaleMatrix = new filament::math::mat4();
	matrix = new filament::math::mat4();
	this->updateMatrix();

	filament::TransformManager& manager = engine->getTransformManager();
	manager.setAccurateTranslationsEnabled(true);
}

Object3D::~Object3D()
{
	engine->destroy(entity);

	this->clear();
	delete translateMatrix;
	delete rotateMatrix;
	delete scaleMatrix;
	delete matrix;
	translateMatrix = nullptr;
	rotateMatrix = nullptr;
	scaleMatrix = nullptr;
	matrix = nullptr;
}

void Object3D::add(Object3D* object)
{
	assert(object != this);
	if (object->parent != nullptr)
	{
		object->parent->remove(object);
	}
	object->parent = this;
	this->children.push_back(object);
}

void Object3D::remove(Object3D* object)
{
	auto iterator = std::find(children.begin(), children.end(), object);
	if (iterator != children.end())
	{
		children.erase(iterator);
	}
}

void Object3D::removeFromParent()
{
	if (parent != nullptr)
	{
		parent->remove(this);
	}
}

void Object3D::clear()
{
	for (auto& child : children)
	{
		child->parent = nullptr;
		delete child;
		child = nullptr;
	}
	children.clear();
}

filament::math::mat4 Object3D::getTransform()
{
	filament::TransformManager& manager = engine->getTransformManager();
	return manager.getTransformAccurate(manager.getInstance(entity));
}

filament::math::mat4 Object3D::getWorldTransform()
{
	filament::TransformManager& manager = engine->getTransformManager();
	return manager.getWorldTransformAccurate(manager.getInstance(entity));
}

void Object3D::setTransform(filament::math::mat4 transform)
{
	filament::TransformManager& manager = engine->getTransformManager();
	return manager.setTransform(manager.getInstance(entity), transform);
}

void Object3D::setTranslation(filament::math::double3 translation)
{
	filament::TransformManager& manager = engine->getTransformManager();
	*translateMatrix = filament::math::mat4::translation(translation);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::setRotation(double radian, filament::math::double3 axis)
{
	filament::TransformManager& manager = engine->getTransformManager();
	*rotateMatrix = filament::math::mat4::rotation(radian, axis);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::setScaling(filament::math::double3 scaling)
{
	filament::TransformManager& manager = engine->getTransformManager();
	*scaleMatrix = filament::math::mat4::scaling(scaling);
	updateMatrix();
	return manager.setTransform(manager.getInstance(entity), *matrix);
}

void Object3D::updateMatrix()
{
	auto worldMatrix = getWorldTransform();
	*matrix = (*translateMatrix) * (*rotateMatrix) * (*scaleMatrix);
}