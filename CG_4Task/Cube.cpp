#include "Cube.h"

void Cube::Setup() {
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	Vertex_buffer vbo(vertices, sizeof(vertices) / sizeof(float));
	vbo.Bind();

	vao.Bind();
	vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	vao.AttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.AttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
}

void Cube::DirecLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties direct) {
	shader->SetVec3("dirLight.direction", direct.direction);
	shader->SetVec3("dirLight.ambient", direct.ambient);
	shader->SetVec3("dirLight.diffuse", direct.diffuse);
	shader->SetVec3("dirLight.specular", direct.specular);
}

void Cube::PointLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties point, std::vector<vec3> positions, float constant, float linear, float quadratic) {
	for (int i = 0; i < 2; i++) {
		shader->SetVec3("pointLights[" + std::to_string(i) + "].position", positions[i]);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].ambient", point.ambient);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].diffuse", point.diffuse);
		shader->SetVec3("pointLights[" + std::to_string(i) + "].specular", point.specular);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].constant", constant);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].linear", linear);
		shader->SetFloat("pointLights[" + std::to_string(i) + "].quadratic", quadratic);
	}
}

void Cube::SpotLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties spot, float constant, float linear, float quadratic, float cutOff, float outerCutOff) {
	shader->SetVec3("spotLight.position", camera.GetPos());
	shader->SetVec3("spotLight.direction", camera.GetFront());
	shader->SetVec3("spotLight.ambient", spot.ambient);
	shader->SetVec3("spotLight.diffuse", spot.diffuse);
	shader->SetVec3("spotLight.specular", spot.specular);
	shader->SetFloat("spotLight.constant", constant);
	shader->SetFloat("spotLight.linear", linear);
	shader->SetFloat("spotLight.quadratic", quadratic);
	shader->SetFloat("spotLight.cutOff", cos(glm::radians(cutOff)));
	shader->SetFloat("spotLight.outerCutOff", cos(glm::radians(outerCutOff)));
}

void Cube::Draw(std::shared_ptr<Shader>& shader, Camera& camera, vec3 position) {
	shader->Use();
	shader->SetMat4("view", camera.GetViewMatrix());
	shader->SetMat4("projection", camera.GetProjectionMatrix());

	vao.Bind();
	math4 model(1.0f);
	model = model.Translate(position);
	vec3 rotate(1.0f, 0.3f, 0.5f);
	model = model.Rotate(glm::radians(30.0f), rotate);
	shader->SetMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
