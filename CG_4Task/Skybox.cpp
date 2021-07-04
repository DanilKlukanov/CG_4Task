#include "Skybox.h"

void Skybox::Setup(std::shared_ptr<Shader>& shader) {
	float vertices[] = {
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
	};

	unsigned int indices[] = {
		0, 1, 2,
		1, 2, 3,

		4, 5, 6,
		5, 6, 7,

		0, 1, 5,
		0, 4, 5,

		2, 3, 7,
		2, 6, 7,

		0, 2, 6,
		0, 4, 6,

		1, 5, 7,
		1, 3, 7
	};

	vao.Bind();
	Vertex_buffer vbo(vertices, sizeof(vertices) / sizeof(float));
	vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	shader->Use();
	shader->SetInt("skybox", 0);
}

void Skybox::Draw(std::shared_ptr<Shader>& shader, Camera& camera) {
	glDepthFunc(GL_LEQUAL);
	shader->Use();
	shader->SetMat4("view", camera.GetRightView());
	shader->SetMat4("projection", camera.GetProjectionMatrix());
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glDepthFunc(GL_LESS);
}
