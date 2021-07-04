#ifndef LIGHT
#define LIGHT

#include <memory>
#include "Shader.h"
#include "Camera.h"
#include "Vertex_array.h"
#include "Vertex_buffer.h"

class Light {
public:
	void Setup();
	void Draw(std::shared_ptr<Shader>& shader, Camera& camera, vec3 position);

private:
	Vertex_array vao;
};

#endif