#ifndef EULER_H
#define EULER_H
#include <iostream> 
namespace MATH {

	class Euler {
	public:

		float xAxis, yAxis, zAxis; /// Rotations in degrees

		/// Just a little utility to populate a Euler
		inline void set(float xAxis_, float yAxis_, float zAxis_) {
			xAxis = xAxis_; yAxis = yAxis_; zAxis = zAxis_;
		}

		inline Euler(float xAxis, float yAxis, float zAxis) {
			set(xAxis, yAxis, zAxis);
		}

		/// Here's a set of constructors
		inline explicit Euler(float s = 0.0f) {
			set(s, s, s);
		}


		/// A copy constructor
		inline Euler(const Euler& e) {
			/// In this context "const" means I promise not to modify anything e points to 
			set(e.xAxis, e.yAxis, e.zAxis);
		}

		/// An assignment operator   
		inline Euler& operator = (const Euler& e) {
			set(e.xAxis, e.yAxis, e.zAxis);
			return *this;
		}

		/// An assignment operator   
		inline void print() {
			printf("%1.8f %1.8f %1.8f\n", xAxis, yAxis, zAxis);
		}
	};
}

#endif