#ifndef CAMERA
#define CAMERA

#include "math/math4.h"
#include "math/vec3.h"
#include "glm/trigonometric.hpp"
#include <SFML/Window.hpp>

class Camera {
public:
	void Setup(vec3& _cameraPos, vec3& _cameraFront, vec3& _cameraUp);
	math4 GetProjectionMatrix();
	math4 GetViewMatrix();
	math4 GetRightView();
	vec3 GetFront();
	vec3 GetPos();

private:
	vec3 cameraPos;
	vec3 cameraFront;
	vec3 cameraUp;
};

#endif