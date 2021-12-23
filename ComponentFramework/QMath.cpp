#include "QMath.h"
#include "Matrix.h"
#include "Euler.h"

using namespace MATH;

float QMath::mag(const Quaternion& q) {
	return(sqrt((q.w * q.w) + (q.v.x * q.v.x) + (q.v.y * q.v.y) + (q.v.z * q.v.z)));
}



Quaternion QMath::fromEuler(const Euler& e) {

	float cosX = cos(0.5f * e.xAxis * DEGREES_TO_RADIANS);
	float cosY = cos(0.5f * e.yAxis * DEGREES_TO_RADIANS);
	float cosZ = cos(0.5f * e.zAxis * DEGREES_TO_RADIANS);
	float sinX = sin(0.5f * e.xAxis * DEGREES_TO_RADIANS);
	float sinY = sin(0.5f * e.yAxis * DEGREES_TO_RADIANS);
	float sinZ = sin(0.5f * e.zAxis * DEGREES_TO_RADIANS);

	/// For XYZ order
	return Quaternion((cosX * cosY * cosZ) + (sinX * sinY * sinZ),
		Vec3((sinX * cosY * cosZ) - (cosX * sinY * sinZ),
			(cosX * sinY * cosZ) + (sinX * cosY * sinZ),
			(cosX * cosY * sinZ) - (sinX * sinY * cosZ)));
}

Matrix3 QMath::toMatrix3(const Quaternion& q) {
	/// This is the fastest way I know...
	return Matrix3((1.0f - 2.0f * q.v.y * q.v.y - 2.0f * q.v.z * q.v.z), (2.0f * q.v.x * q.v.y + 2.0f * q.v.z * q.w), (2.0f * q.v.x * q.v.z - 2.0f * q.v.y * q.w),
		(2.0f * q.v.x * q.v.y - 2.0f * q.v.z * q.w), (1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.z * q.v.z), (2.0f * q.v.y * q.v.z + 2.0f * q.v.x * q.w),
		(2.0f * q.v.x * q.v.z + 2.0f * q.v.y * q.w), (2.0f * q.v.y * q.v.z - 2 * q.v.x * q.w), (1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.y * q.v.y));
}

Matrix4 QMath::toMatrix4(const Quaternion& q) {
	/// This is the fastest way I know...
	return Matrix4((1.0f - 2.0f * q.v.y * q.v.y - 2.0f * q.v.z * q.v.z), (2.0f * q.v.x * q.v.y + 2.0f * q.v.z * q.w), (2.0f * q.v.x * q.v.z - 2.0f * q.v.y * q.w), 0.0f,
		(2.0f * q.v.x * q.v.y - 2.0f * q.v.z * q.w), (1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.z * q.v.z), (2.0f * q.v.y * q.v.z + 2.0f * q.v.x * q.w), 0.0f,
		(2.0f * q.v.x * q.v.z + 2.0f * q.v.y * q.w), (2.0f * q.v.y * q.v.z - 2 * q.v.x * q.w), (1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.y * q.v.y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	/// ... but this is the coolest. My way is just a bit faster on single processor machines,
	/// this method is faster on parallel multicore machines.

	//Matrix4 m1( q.w,  q.v.z,  -q.v.y,  q.v.x,
	//		-q.v.z,   q.w,   q.v.x,  q.v.y,
	//		q.v.y,  -q.v.x,   q.w,  q.v.z,
	//		-q.v.x,  -q.v.y,  -q.v.z,  q.w);
	//
	//Matrix4 m2( q.w,   q.v.z,  -q.v.y,  -q.v.x,
	//			-q.v.z,   q.w,   q.v.x,  -q.v.y,
	//			q.v.y,  -q.v.x,   q.w,  -q.v.z,
	//			-q.v.x,   q.v.y,   q.v.z,   q.w);
	//return m1 * m2;

}

