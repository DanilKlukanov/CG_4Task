#include "Core.h"

Core::Core(sf::ContextSettings _settings, bool& _go) :
	window(sf::VideoMode(width, height, 32), "CG_4Task", sf::Style::Titlebar | sf::Style::Close, _settings), go(_go) {}

void Core::Setup() {
	input_comp.set_component(InputManager());

	render.Init();

	Shader shader_cube("shaders/light_tex.vs", "shaders/light_tex.fs");
	Shader shader_point("shaders/cube.vs", "shaders/cube.fs");

	//освещение
	Object light_comp;
	light_comp.set_direct_light(Properties(vec3(-0.2f, -1.0f, -0.3f), vec3(0.05f, 0.05f, 0.05f), vec3(0.4f, 0.4f, 0.4f), vec3(0.5f, 0.5f, 0.5f)));
	light_comp.set_point_light(Properties(vec3(0.05f, 0.05f, 0.05f), vec3(0.8f, 0.8f, 0.8f), vec3(1.0f, 1.0f, 1.0f)));
	light_comp.set_spot_light(Properties(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), vec3(1.0f, 1.0f, 1.0f)));

	//кубы
	vec3 pos_cube[] = {
		vec3(1.5f,  2.0f, -2.5f),
		vec3(1.5f,  0.2f, -1.5f),
		vec3(-1.3f,  1.0f, -1.5f),
		vec3(1.3f, -2.0f, -2.5f)
	};
	for (int i = 0; i < 4; i++) {
		Object cube_comp;
		cube_comp.set_component(pos_cube[i]);
		cube_comp.set_component(std::make_shared<Cube>());
		cube_comp.set_component(std::make_shared<Shader>(shader_cube));
		scene.push_object(cube_comp);
	}

	//световые кубы
	vec3 pos_point[] = {
		vec3(1.2f, 0.0f, 2.0f),
		vec3(1.2f, 0.0f, -4.0f),
	};
	for (int i = 0; i < 2; i++) {
		Object point_comp;
		point_comp.set_component(pos_point[i]);
		point_comp.set_component(std::make_shared<Light>());
		point_comp.set_component(std::make_shared<Shader>(shader_point));
		scene.push_object(point_comp);
	}

	//камера, начальные данные
	Object camera_comp;
	camera_comp.set_camera_up(vec3(0.0f, 4.0f, 0.0f));
	camera_comp.set_camera_pos(vec3(-2.0f, 0.0f, 4.0f));
	camera_comp.set_camera_front(vec3(0.0f, 0.0f, -1.0f));

	//скайбокс
	Shader shader_skybox("shaders/skybox.vs", "shaders/skybox.fs");

	Object skybox_comp;
	skybox_comp.set_component(std::make_shared<Skybox>());
	skybox_comp.set_component(std::make_shared<Shader>(shader_skybox));
	scene.push_object(skybox_comp);

	Object tex_comp;
	tex_comp.set_tex_cube(Texture("textures/box.png"));

	std::string path = "textures/";
	std::vector<std::string> faces{
		path + "right.png",
		path + "left.png",
		path + "top.png",
		path + "bottom.png",
		path + "front.png",
		path + "back.png"
	};

	tex_comp.set_tex_skybox(Texture(faces));

	render.Setup(scene.get_objects());
}

void Core::Input() {
	sf::Event windowEvent;
	while (window.pollEvent(windowEvent)) {
		input_comp.set_event(windowEvent);
		input_comp.StartInput(go);
	};
}

void Core::Update() {
	render.Update(scene.get_objects());
}

void Core::PostUpdate() {
	render.Draw(scene.get_objects());
	window.display();
}
