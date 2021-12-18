#ifndef FWLAB_GEOMETRY_LINES_GEOMETRY_H
#define FWLAB_GEOMETRY_LINES_GEOMETRY_H
#include <stdint.h>
#include "Geometry.h"
#include "../Context.h"

/// <summary>
/// Ïß
/// </summary>
class LinesGeometry : public Geometry {
public:
	LinesGeometry(Context* context);
	virtual ~LinesGeometry();
	void create(float vertices[], uint32_t verticesSize);

private:
	uint16_t* indices = nullptr;
};
#endif