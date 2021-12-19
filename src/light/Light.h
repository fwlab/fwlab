#ifndef FWLAB_LIGHT_H
#define FWLAB_LIGHT_H
#include <utils/Entity.h>
#include "../Context.h"

/// <summary>
/// นโ
/// </summary>
class Light {
public:
	Light(Context* context);
	virtual ~Light();
	utils::Entity entity;
	Light* create();

private:
	Context* context;
};

#endif