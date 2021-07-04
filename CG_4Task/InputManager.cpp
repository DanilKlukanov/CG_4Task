#include "InputManager.h"

InputManager::InputManager() {}

void InputManager::MouseInput(vec3& cameraFront, sf::Event windowEvent) {
	float xoffset = windowEvent.mouseMove.x - lastX;
	float yoffset = lastY - windowEvent.mouseMove.y;
	lastX = windowEvent.mouseMove.x;
	lastY = windowEvent.mouseMove.y;

	yaw += (xoffset * speed_mouse);
	pitch += (yoffset * speed_mouse);

	vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = direction.Normalize();
}

void InputManager::KeyboardInput(vec3& cameraPos, vec3& cameraFront, vec3& cameraUp) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		cameraPos += cameraFront * speed_camera;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		cameraPos -= cameraFront * speed_camera;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vec3 result = cameraFront.VectorMultiplication(cameraUp);
		cameraPos -= result.Normalize() * speed_camera;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vec3 result = cameraFront.VectorMultiplication(cameraUp);
		cameraPos += result.Normalize() * speed_camera;
	}
}

void InputManager::CheckInput(sf::Event window_event, vec3& cameraPos, vec3& cameraFront, vec3& cameraUp, bool& go) {
	switch (window_event.type) {
	case sf::Event::Closed:
		go = false;
		break;
	case sf::Event::KeyPressed:
		KeyboardInput(cameraPos, cameraFront, cameraUp);
		break;
	case sf::Event::MouseMoved:
		MouseInput(cameraFront, window_event);
		break;
	default:
		break;
	}
}
