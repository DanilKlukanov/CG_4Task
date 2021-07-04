#include "Component.h"

void Component::StartInput(bool& go) {
	input_manager.CheckInput(window_event, cameraPos, cameraFront, cameraUp, go);
	camera.Setup(cameraPos, cameraFront, cameraUp);
}

void Component::Setup(unsigned int id) {
	camera.Setup(cameraPos, cameraFront, cameraUp);

	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Setup();

	if (light.find(id) != light.end())
		light.at(id)->Setup();

	skybox->Setup(shaders.at(id));
}

void Component::Draw(unsigned int id) {
	if (cubes.find(id) != cubes.end())
		cubes.at(id)->Draw(shaders.at(id), camera, positions.at(id));

	if (light.find(id) != light.end())
		light.at(id)->Draw(shaders.at(id), camera, positions.at(id));

	skybox->Draw(shaders.at(id), camera);
}

void Component::UpdateLight(unsigned int id) {
	std::vector<vec3> point_pos;
	for (auto const& point : light) {
		point_pos.push_back(positions.at(point.first));
	}

	if (cubes.find(id) != cubes.end()) {
		shaders.at(id)->Use();
		shaders.at(id)->SetVec3("viewPos", camera.GetPos());
		shaders.at(id)->SetFloat("material.shininess", shininess);
		cubes.at(id)->DirecLight(shaders.at(id), camera, directional);
		cubes.at(id)->PointLight(shaders.at(id), camera, point, point_pos, constant, linear, quadratic);
		cubes.at(id)->SpotLight(shaders.at(id), camera, spot, constant, linear, quadratic, cutOff, outerCutOff);
	}
}
