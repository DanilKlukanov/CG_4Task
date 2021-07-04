#include "Render.h"

Render::Render() {}

void Render::Init() {
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Error:: glew not init =(" << std::endl;
		exit(-1);
	}
	glEnable(GL_DEPTH_TEST);
}

void Render::Setup(std::vector<Object>& objects) {
	for (auto& object : objects) {
		object.Setup();
	}
}

void Render::Update(std::vector<Object>& objects) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto& object : objects) {
		object.UpdateLight();
	}
}

void Render::Draw(std::vector<Object>& objects) {
	for (int count = 0; count < objects.size(); count++) {
		objects[count].Draw();
	}
}
