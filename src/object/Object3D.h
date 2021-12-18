#ifndef FWLAB_OBJECT_OBJECT3D_H
#define FWLAB_OBJECT_OBJECT3D_H
#include <math/mat4.h>
#include "../Context.h"

/// <summary>
/// ÈýÎ¬ÎïÌå
/// </summary>
class Object3D
{
public:
	Object3D(Context* context);
	virtual ~Object3D();
	Object3D* create();
	utils::Entity entity;
	filament::math::mat4 getTransform();
	filament::math::mat4 getWorldTransform();
	void setTransform(filament::math::mat4 transform);
	void setTranslation(filament::math::double3 translation);
	void setRotation(double radian, filament::math::double3 axis);
	void setScaling(filament::math::double3 scaling);

protected:
	Context* context;
};

#endif