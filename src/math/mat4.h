#ifndef FWLAB_MATH_MAT4_H
#define FWLAB_MATH_MAT4_H
#include <math/mat4.h>
#include <math/quat.h>
#include <math/vec3.h>

namespace fwlab::math
{
	filament::math::mat4 compose(filament::math::double3 position, filament::math::quat quaternion, filament::math::double3 scale);

	void decompose(filament::math::mat4 mat, filament::math::double3& position, filament::math::quat& quaternion, filament::math::double3& scale);
}

#endif