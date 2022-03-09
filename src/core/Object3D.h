#ifndef FWLAB_CORE_OBJECT3D_H
#define FWLAB_CORE_OBJECT3D_H
#include <string>
#include <vector>
#include <math/mat4.h>
#include <math/quat.h>
#include <math/vec3.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>

namespace fwlab::core
{
	class Object3D
	{
	public:
		Object3D();
		virtual ~Object3D();
		::utils::Entity getEntity() const;
		void setEntity(::utils::Entity entity);
		filament::math::double3 getPosition() const;
		void setPosition(filament::math::double3 position);
		filament::math::quat getRotation() const;
		void setRotation(filament::math::quat rotation);
		void setRotation(filament::math::double3 axis, double angle);
		filament::math::double3 getScale() const;
		void setScale(filament::math::double3 scale);
		filament::math::mat4 getMatrix() const;
		void setMatrix(filament::math::mat4 matrix);
		filament::math::mat4 getMatrixWorld() const;

		virtual bool add(Object3D* child);
		virtual bool remove(Object3D* child);
		bool has(Object3D* child) const;
		std::vector<Object3D*> getChildren() const;
		Object3D* getParent() const;
		void setParent(Object3D* parent);

		std::string getName() const;
		void setName(std::string name);

		// Entity Manager
		uint8_t getGenerationForIndex(size_t index) const;
		bool isAlive() const;
		void registerListener(::utils::EntityManager::Listener* l);
		void unregisterListener(::utils::EntityManager::Listener* l);

	protected:
		void updateMatrix();
		filament::math::double3 position = { 0, 0, 0 };
		filament::math::quat rotation = { 1, 0, 0, 0 };
		filament::math::double3 scale = { 1, 1, 1 };
		filament::math::mat4 matrix;

		::utils::Entity entity;
		Object3D* parent = nullptr;
		std::vector<Object3D*> children;

		std::string name;

	private:
		static ::utils::Entity defaultParent;
	};
}

#endif