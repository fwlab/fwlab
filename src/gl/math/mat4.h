#ifndef GL_MAT4_H
#define GL_MAT4_H
#include <math/mat4.h>
#include <math/quat.h>
#include <math/vec3.h>

namespace gl::math
{
	filament::math::mat4 compose(filament::math::double3 position, filament::math::quat quaternion, filament::math::double3 scale) noexcept;
	void decompose(filament::math::mat4 mat, filament::math::double3 &position, filament::math::quat &quaternion, filament::math::double3 &scale) noexcept;
}

#endif