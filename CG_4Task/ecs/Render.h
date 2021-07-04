#ifndef RENDER
#define RENDER

#include <iostream>
#include <GL/glew.h>
#include "Object.h"

class Render {
public:
	Render();
	void Init();
	void Setup(std::vector<Object>& objects);
	void Update(std::vector<Object>& objects);
	void Draw(std::vector<Object>& objects);
};

#endif