#include "mat4.h"

using namespace filament::math;

mat4 gl::math::compose(double3 position, quat quaternion, double3 scale) noexcept
{
	auto x = quaternion.x;
	auto y = quaternion.y;
	auto z = quaternion.z;
	auto w = quaternion.w;

	auto x2 = x + x;
	auto y2 = y + y;
	auto z2 = z + z;
	auto xx = x * x2;
	auto xy = x * y2;
	auto xz = x * z2;
	auto yy = y * y2;
	auto yz = y * z2;
	auto zz = z * z2;
	auto wx = w * x2;
	auto wy = w * y2;
	auto wz = w * z2;

	auto sx = scale.x;
	auto sy = scale.y;
	auto sz = scale.z;

	mat4 mat;
	mat[0][0] = (1 - (yy + zz)) * sx;
	mat[0][1] = (xy + wz) * sx;
	mat[0][2] = (xz - wy) * sx;
	mat[0][3] = 0;

	mat[1][0] = (xy - wz) * sy;
	mat[1][1] = (1 - (xx + zz)) * sy;
	mat[1][2] = (yz + wx) * sy;
	mat[1][3] = 0;

	mat[2][0] = (xz + wy) * sz;
	mat[2][1] = (yz - wx) * sz;
	mat[2][2] = (1 - (xx + yy)) * sz;
	mat[2][3] = 0;

	mat[3][0] = position.x;
	mat[3][1] = position.y;
	mat[3][2] = position.z;
	mat[3][3] = 1;

	return mat;
}

void gl::math::decompose(mat4 mat, double3& position, quat& quaternion, double3& scale) noexcept
{

}