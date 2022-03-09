#include <filament/TransformManager.h>
#include "../math/mat4.h"
#include "Object3D.h"
#include "../context/context.h"

namespace fwlab::core
{
	::utils::Entity Object3D::defaultParent;

	Object3D::Object3D()
	{
		auto engine = app->getEngine();

		auto& manager = engine->getTransformManager();
		manager.setAccurateTranslationsEnabled(true);
	}

	Object3D::~Object3D()
	{
		auto engine = app->getEngine();

		engine->destroy(entity);
	}

	::utils::Entity Object3D::getEntity() const
	{
		return entity;
	}

	void Object3D::setEntity(::utils::Entity entity)
	{
		auto engine = app->getEngine();

		if (this->entity)
		{
			engine->destroy(this->entity);
		}
		this->entity = entity;
	}

	filament::math::double3 Object3D::getPosition() const
	{
		return position;
	}

	void Object3D::setPosition(filament::math::double3 position)
	{
		this->position = position;
		updateMatrix();
	}

	filament::math::quat Object3D::getRotation() const
	{
		return rotation;
	}

	void Object3D::setRotation(filament::math::quat rotation)
	{
		this->rotation = rotation;
		updateMatrix();
	}

	void Object3D::setRotation(filament::math::double3 axis, double angle)
	{
		this->rotation = filament::math::quat::fromAxisAngle(axis, angle);
		updateMatrix();
	}

	filament::math::double3 Object3D::getScale() const
	{
		return scale;
	}

	void Object3D::setScale(filament::math::double3 scale)
	{
		this->scale = scale;
		updateMatrix();
	}

	filament::math::mat4 Object3D::getMatrix() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getTransformManager();
		return manager.getTransformAccurate(manager.getInstance(entity));
	}

	void Object3D::setMatrix(filament::math::mat4 matrix)
	{
		auto engine = app->getEngine();

		this->matrix = matrix;
		auto& manager = engine->getTransformManager();
		manager.setTransform(manager.getInstance(entity), matrix);
	}

	filament::math::mat4 Object3D::getMatrixWorld() const
	{
		auto engine = app->getEngine();

		filament::TransformManager& manager = engine->getTransformManager();
		return manager.getWorldTransformAccurate(manager.getInstance(entity));
	}

	void Object3D::updateMatrix()
	{
		auto engine = app->getEngine();

		matrix = math::compose(position, rotation, scale);
		auto& manager = engine->getTransformManager();
		manager.setTransform(manager.getInstance(entity), matrix);
	}

	bool Object3D::add(Object3D* child)
	{
		if (has(child))
		{
			return false;
		}
		auto engine = app->getEngine();

		children.push_back(child);

		auto& manager = engine->getTransformManager();
		manager.setParent(manager.getInstance(child->entity), manager.getInstance(entity));

		return true;
	}

	bool Object3D::remove(Object3D* child)
	{
		auto iter = std::find(children.begin(), children.end(), child);
		if (iter == children.end())
		{
			return false;
		}
		children.erase(iter);

		auto engine = app->getEngine();
		child->parent = nullptr;

		auto& manager = engine->getTransformManager();
		manager.setParent(manager.getInstance(child->entity), manager.getInstance(Object3D::defaultParent));

		return true;
	}

	bool Object3D::has(Object3D* child) const
	{
		return std::find(children.begin(), children.end(), child) != children.end();
	}

	std::vector<Object3D*> Object3D::getChildren() const
	{
		return children;
	}

	Object3D* Object3D::getParent() const
	{
		return parent;
	}

	void Object3D::setParent(Object3D* parent)
	{
		if (this->parent)
		{
			this->parent->remove(this);
		}

		auto engine = app->getEngine();

		assert(parent != this);

		this->parent = parent;

		auto& manager = engine->getTransformManager();
		manager.setParent(manager.getInstance(entity), manager.getInstance(parent->entity));
	}

	std::string Object3D::getName() const
	{
		return name;
	}

	void Object3D::setName(std::string name)
	{
		this->name = name;
	}

	// Entity Manager
	uint8_t Object3D::getGenerationForIndex(size_t index) const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getEntityManager();
		return manager.getGenerationForIndex(index);
	}

	bool Object3D::isAlive() const
	{
		auto engine = app->getEngine();

		auto& manager = engine->getEntityManager();
		return manager.isAlive(entity);
	}

	void Object3D::registerListener(::utils::EntityManager::Listener* l)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getEntityManager();
		manager.registerListener(l);
	}

	void Object3D::unregisterListener(::utils::EntityManager::Listener* l)
	{
		auto engine = app->getEngine();

		auto& manager = engine->getEntityManager();
		manager.unregisterListener(l);
	}
}