#ifndef GL_CORE_OBJECT3D_H
#define GL_CORE_OBJECT3D_H
#include <vector>
#include <math/mat4.h>
#include <math/quat.h>
#include <math/vec3.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>

namespace gl::core
{
	class Object3D
	{
	public:
		Object3D();
		virtual ~Object3D();
		utils::Entity getEntity() const noexcept;
		void setEntity(utils::Entity entity) noexcept;
		filament::math::double3 getPosition() const noexcept;
		void setPosition(filament::math::double3 position) noexcept;
		filament::math::quat getRotation() const noexcept;
		void setRotation(filament::math::quat rotation) noexcept;
		void setRotation(filament::math::double3 axis, double angle) noexcept;
		filament::math::double3 getScale() const noexcept;
		void setScale(filament::math::double3 scale) noexcept;
		filament::math::mat4 getMatrix() const noexcept;
		void setMatrix(filament::math::mat4 matrix) noexcept;
		filament::math::mat4 getMatrixWorld() const noexcept;

		// Transform Manager
		Object3D *getParent() const noexcept;
		void setParent(Object3D *parent) noexcept;
		std::vector<Object3D *> getChildren() const noexcept;
		bool hasChild(Object3D *child) const noexcept;
		void addChild(Object3D *child) noexcept;
		void removeChild(Object3D *child) noexcept;

		// Entity Manager
		uint8_t getGenerationForIndex(size_t index) const noexcept;
		bool isAlive() const noexcept;
		void registerListener(utils::EntityManager::Listener *l) noexcept;
		void unregisterListener(utils::EntityManager::Listener *l) noexcept;

	protected:
		void updateMatrix();
		utils::Entity entity;
		filament::math::double3 position = {0, 0, 0};
		filament::math::quat rotation = {1, 0, 0, 0};
		filament::math::double3 scale = {1, 1, 1};
		filament::math::mat4 matrix;

		Object3D *parent = nullptr;
		std::vector<Object3D *> children;
		static utils::Entity defaultParent;
	};
}

#endif