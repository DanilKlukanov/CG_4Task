#ifndef CUBE
#define CUBE

#include <memory>
#include "glm/geometric.hpp"
#include "Properties.h"
#include "math/vec3.h"
#include "Shader.h"
#include "Camera.h"
#include "Vertex_array.h"
#include "Vertex_buffer.h"

class Cube {
public:
	void Setup();
	void DirecLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties direct);
	void PointLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties point, std::vector<vec3> positions, float constant, float linear, float quadratic);
	void SpotLight(std::shared_ptr<Shader>& shader, Camera& camera, Properties spot, float constant, float linear, float quadratic, float cutOff, float outerCutOff);
	void Draw(std::shared_ptr<Shader>& shader, Camera& camera, vec3 position);

private:
	Vertex_array vao;
};

#endif