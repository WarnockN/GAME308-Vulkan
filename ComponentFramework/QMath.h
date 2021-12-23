#ifndef QMATH_H
#define QMATH_H
#include <cmath>
#include "Quaternion.h"

#include "Matrix.h"
namespace MATH {

	class Euler;

	class QMath {
	public:
		static float mag(const Quaternion& q);
		static  Quaternion fromEuler(const Euler& e);
		static  Matrix3 toMatrix3(const Quaternion& q);
		static  Matrix4 toMatrix4(const Quaternion& q);




	};
}
#endif