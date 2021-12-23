#ifndef QUATERTNION_H
#define QUATERTNION_H
#include <iostream>
#include "VMath.h"
#include "Matrix.h"

///A quarternion can be written as a scalar plus a 3-vector (Vec3) component

namespace  MATH {
	struct Quaternion {
		float w;
		Vec3 v; /// These are the ijk components of the Quaternion 

		/// Just a little utility to populate a quaternion
		inline void set(float w_, float x_, float y_, float z_) {
			w = w_; v.x = x_; v.y = y_; v.z = z_;
			/// The memory layout is understood
		  /**static_cast<float*>(&w+0) = w_;
			*static_cast<float*>(&w+1) = x_;
			*static_cast<float*>(&w+2) = y_;
			*static_cast<float*>(&w+3) = z_;*/
		}
		/// This is the unit quaterion by definition 
		inline Quaternion() {
			set(1.0f, 0.0f, 0.0f, 0.0f);
		}

		inline Quaternion(float w_, float x_, float y_, float z_) {
			set(w_, x_, y_, z_);
		}
		inline Quaternion(float w_, const Vec3& v) {
			set(w_, v.x, v.y, v.z);
		}

		/// A copy constructor
		inline Quaternion(const Quaternion& q) {
			set(q.w, q.v.x, q.v.y, q.v.z);
		}

		/// An assignment operator   
		inline Quaternion& operator = (const Quaternion& q) {
			set(q.w, q.v.x, q.v.y, q.v.z);
			return *this;
		}

		/// Now we can use the Quaternion like an array but we'll need two overloads
		inline const float operator [] (int index) const {  /// This one is for reading the Quaternion as if where an array
			return *((float*)this + index);
		}

		inline float& operator [] (int index) {	/// This one is for writing to the Quaternion as if where an array.  
			return *((float*)this + index);
		}
		/// Take the negative of a Quaternion
		inline const Quaternion operator - () const {
			return Quaternion(-w, -v.x, -v.y, -v.z);
		}

		/// Multiply a two quaternions - using the right-hand rule  
		inline const Quaternion operator * (const Quaternion& q) const {
			Vec3 ijk(w * q.v + q.w * v + VMath::cross(v, q.v));
			return Quaternion(w * q.w - VMath::dot(v, q.v), Vec3(ijk));
		}

		/// Multiply a quaternion by a Vec3 - using the right-hand rule 
		inline const Quaternion operator * (const Vec4& v_) const {
			Vec3 ijk(w * v + v_.w * v + VMath::cross(v, v_));
			return Quaternion(w * v_.w - VMath::dot(v, v_), Vec3(ijk));
		}

		inline const Quaternion conjugate() const {
			return Quaternion(w, -v.x, -v.y, -v.z);
		}


		inline void print() {
			printf("%1.8f %1.8f %1.8f %1.8f\n", v.x, v.y, v.z, w);
		}

	};
}
#endif