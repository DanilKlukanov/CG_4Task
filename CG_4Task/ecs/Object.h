#ifndef OBJECT
#define OBJECT

#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../math/vec3.h"
#include "../InputManager.h"
#include "../Properties.h"
#include "../Camera.h"
#include "../Shader.h"
#include "../Light.h"
#include "../Cube.h"
#include "../Skybox.h"
#include "Component.h"

static Component ecs;

class Object {
public:
	Object();
	void Setup();
	void Draw();
	void UpdateLight();
	void StartInput(bool& go);

	void set_component(vec3 position);
	void set_component(std::shared_ptr<Cube> cube);
	void set_component(std::shared_ptr<Light> point);
	void set_component(std::shared_ptr<Shader> shader);
	void set_component(std::shared_ptr<Skybox> _skybox);
	void set_component(InputManager _input_manager);

	void set_event(sf::Event _window_event);
	void set_tex_skybox(Texture _box);
	void set_tex_cube(Texture _cube);
	void set_camera_pos(vec3 _position);
	void set_camera_front(vec3 _front);
	void set_camera_up(vec3 _up);
	void set_direct_light(Properties _direct);
	void set_point_light(Properties _point);
	void set_spot_light(Properties _spot);

private:
	int id = 0;
};


#endif