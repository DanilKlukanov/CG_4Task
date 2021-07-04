#ifndef SKYBOX
#define SKYBOX

#include <memory>
#include "Shader.h"
#include "Camera.h"
#include "Vertex_array.h"
#include "Vertex_buffer.h"

class Skybox {
public:
	void Setup(std::shared_ptr<Shader>& shader);
	void Draw(std::shared_ptr<Shader>& shader, Camera& camera);

private:
	Vertex_array vao;
};

#endif