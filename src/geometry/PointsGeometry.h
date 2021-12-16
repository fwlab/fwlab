#ifndef FWLAB_GEOMETRY_POINTS_GEOMETRY_H
#define FWLAB_GEOMETRY_POINTS_GEOMETRY_H
#include <stdint.h>
#include "Geometry.h"
#include "../Context.h"

/// <summary>
/// µãÔÆ
/// </summary>
class PointsGeoemtry : public Geometry {
public:
	PointsGeoemtry(Context* context);
	virtual ~PointsGeoemtry();
	void create(float vertices[], uint32_t verticesSize);

private:
	uint16_t* indices = nullptr;
};
#endif