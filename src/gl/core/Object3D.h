#ifndef GL_CORE_OBJECT3D_H
#define GL_CORE_OBJECT3D_H
#include <math/mat4.h>
#include "../Context.h"

namespace gl::core
{
	class Object3D
	{
	public:
		Object3D(Context* context);
		virtual ~Object3D();
		virtual void create();
		void add(Object3D* object);
		void remove(Object3D* object);
		void removeFromParent();
		void clear();
		filament::math::mat4 getTransform();
		filament::math::mat4 getWorldTransform();
		void setTransform(filament::math::mat4 transform);
		void setTranslation(filament::math::double3 translation);
		void setRotation(double radian, filament::math::double3 axis);
		void setScaling(filament::math::double3 scaling);
		utils::Entity entity;
		Object3D* parent;
		std::vector<Object3D*> children;

	protected:
		Context* context = nullptr;
		filament::math::mat4* translateMatrix = nullptr;
		filament::math::mat4* rotateMatrix = nullptr;
		filament::math::mat4* scaleMatrix = nullptr;
		filament::math::mat4* matrix = nullptr;
		void updateMatrix();
	};
}

#endif