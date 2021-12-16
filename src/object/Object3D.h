#ifndef FWLAB_OBJECT_OBJECT3D_H
#define FWLAB_OBJECT_OBJECT3D_H
#include "../Context.h"

/// <summary>
/// ÈýÎ¬ÎïÌå
/// </summary>
class Object3D
{
public:
	Object3D(Context* context);
	virtual ~Object3D();
	void create();

protected:
	Context* context;
};

#endif