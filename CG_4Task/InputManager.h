#ifndef INPUTMANAGER
#define INPUTMANAGER

#include "glm/trigonometric.hpp"
#include "math/vec3.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class InputManager {
public:
	InputManager();
	void CheckInput(sf::Event window_event, vec3& cameraPos, vec3& cameraFront, vec3& cameraUp, bool& go);

private:
	int width = 800;
	int height = 600;

	float pitch = 0.0f;
	float yaw = -90.0f;
	float speed_camera = 0.05f;
	float lastY = width / 2.0f;
	float lastX = height / 2.0f;
	float speed_mouse = 0.35f;

	void MouseInput(vec3& cameraFront, sf::Event windowEvent);
	void KeyboardInput(vec3& cameraPos, vec3& cameraFront, vec3&);
};

#endif