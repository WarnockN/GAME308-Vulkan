#include "Camera.h"

Camera::Camera(const float fovY_, const float aspectRatio_, const float near_, const float far_) {
	projection = MMath::perspective(fovY_, aspectRatio_, near_, far_);
	view = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	cout << "The Camera is ready\n" << endl;
}

Camera::~Camera() {
	/// There's nothing to do here yet
}

void Camera::Perspective(const float fovY_, const float aspectRatio_, const float near_, const float far_) {
	projection = MMath::perspective(fovY_, aspectRatio_, near_, far_);
}

void Camera::LookAt(const Vec3& eye, const Vec3& at, const Vec3& up) {
	view = MMath::lookAt(eye, at, up);
	view.print();
}

void Camera::SetPosition(const Vec3& position_) { translate = MMath::translate(position_); }

void Camera::SetOrientation(const float angle, const Vec3& axis) { rotation = MMath::rotate(angle, axis); }

void Camera::UpdateViewMatrix() {
	
}

