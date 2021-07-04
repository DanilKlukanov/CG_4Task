#include "Object.h"

Object::Object() {
	static int id_sup;
	id = id_sup;
	id_sup++;
}

void Object::Setup() {
	ecs.Setup(id);
}

void Object::Draw() {
	ecs.Draw(id);
}

void Object::UpdateLight() {
	ecs.UpdateLight(id);
}

void Object::StartInput(bool& go) {
	ecs.StartInput(go);
}

void Object::set_component(vec3 position) {
	ecs.positions[id] = position;
}

void Object::set_component(std::shared_ptr<Cube> cube) {
	ecs.cubes[id] = cube;
}

void Object::set_component(std::shared_ptr<Light> point) {
	ecs.light[id] = point;
}

void Object::set_component(std::shared_ptr<Shader> shader) {
	ecs.shaders[id] = shader;
}

void Object::set_component(std::shared_ptr<Skybox> _skybox) {
	ecs.skybox = _skybox;
}

void Object::set_component(InputManager _input_manager) {
	ecs.input_manager = _input_manager;
}

void Object::set_event(sf::Event _window_event) {
	ecs.window_event = _window_event;
}

void Object::set_tex_skybox(Texture _box) {
	ecs.box = _box;
}

void Object::set_tex_cube(Texture _cube) {
	ecs.cube = _cube;
}

void Object::set_camera_pos(vec3 _position) {
	ecs.cameraPos = _position;
}

void Object::set_camera_front(vec3 _front) {
	ecs.cameraFront = _front;
}

void Object::set_camera_up(vec3 _up) {
	ecs.cameraUp = _up;
}

void Object::set_direct_light(Properties _direct) {
	ecs.directional = _direct;
}

void Object::set_point_light(Properties _point) {
	ecs.point = _point;
}

void Object::set_spot_light(Properties _spot) {
	ecs.spot = _spot;
}