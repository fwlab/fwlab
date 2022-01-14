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
	auto& te = mat;

	double3 _v1;

	_v1.x = te[0][0];
	_v1.y = te[0][1];
	_v1.z = te[0][2];
	auto sx = length(_v1);
	_v1.x = te[1][0];
	_v1.y = te[1][1];
	_v1.z = te[1][2];
	auto sy = length(_v1);
	_v1.x = te[2][0];
	_v1.y = te[2][1];
	_v1.z = te[2][2];
	auto sz = length(_v1);

	// if determine is negative, we need to invert one scale
	if (det(te) < 0)
		sx = -sx;

	position.x = te[3][0];
	position.y = te[3][1];
	position.z = te[3][2];

	// scale the rotation part
	mat4 _m1(te);

	auto invSX = 1 / sx;
	auto invSY = 1 / sy;
	auto invSZ = 1 / sz;

	_m1[0][0] *= invSX;
	_m1[0][1] *= invSX;
	_m1[0][2] *= invSX;

	_m1[1][0] *= invSY;
	_m1[1][1] *= invSY;
	_m1[1][2] *= invSY;

	_m1[2][0] *= invSZ;
	_m1[2][1] *= invSZ;
	_m1[2][2] *= invSZ;

	quaternion = _m1.toQuaternion();

	scale.x = sx;
	scale.y = sy;
	scale.z = sz;
}