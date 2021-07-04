#include "Light.h"

void Light::Setup() {
	vao.Bind();
	vao.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
}

void Light::Draw(std::shared_ptr<Shader>& shader, Camera& camera, vec3 position) {
	shader->Use();
	shader->SetMat4("view", camera.GetViewMatrix());
	shader->SetMat4("projection", camera.GetProjectionMatrix());

	math4 model(1.0f);
	model = model.Translate(position);
	model = model.Scale(vec3(0.4f));
	shader->SetMat4("model", model);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
