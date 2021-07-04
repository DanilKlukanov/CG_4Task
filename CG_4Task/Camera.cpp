#include "Camera.h"

void Camera::Setup(vec3& _cameraPos, vec3& _cameraFront, vec3& _cameraUp) {
	cameraPos = _cameraPos;
	cameraFront = _cameraFront;
	cameraUp = _cameraUp;
}

math4 Camera::GetProjectionMatrix() {
	math4 projection;
	return projection.Perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

math4 Camera::GetViewMatrix() {
	math4 view;
	return view.LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

math4 Camera::GetRightView() {
	math4 view = GetViewMatrix();
	view.matrix[3][0] = 0;
	view.matrix[3][1] = 0;
	view.matrix[3][2] = 0;
	view.matrix[3][3] = 0;
	return view;
}

vec3 Camera::GetPos() {
	return cameraPos;
}

vec3 Camera::GetFront() {
	return cameraFront;
}