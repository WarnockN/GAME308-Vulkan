#ifndef CAMERA_H
#define CAMERA_H

#include "Matrix.h"
#include "MMath.h"

using namespace MATH;
using namespace std;

class Camera {
private:
	Matrix4 projection, view, rotation, translate;

	float fov, nearPlane, farPlane;

public:
	Camera(const float fovY_, const float aspectRatio_, const float near_, const float far_);
	~Camera();

	void Perspective(const float fovY_, const float aspectRatio_, const float near_, const float far_);
	void LookAt(const Vec3& eye, const Vec3& at, const Vec3& up);
	void SetPosition(const Vec3& position_);
	void SetOrientation(const float angle, const Vec3& axis);

	void UpdateViewMatrix();


	inline Matrix4 GetProjectionMatrix() const { return projection; }
	inline void SetProjectionMatrix(Matrix4 projection_) { projection = projection_; }

	inline Matrix4 GetViewMatrix() const { return rotation * translate; }
	inline void SetViewMatrix(Matrix4 view_) { view = view_; }

	inline Matrix4 GetRotationMatrix() const { return rotation; }
	inline void SetRotationMatrix(Matrix4 rotation_) { rotation = rotation_; }

	inline Matrix4 GetTranslationMatrix() const { return translate; }
	inline void SetTranslationMatrix(Matrix4 translate_) { translate = translate_; }

	
};

#endif

