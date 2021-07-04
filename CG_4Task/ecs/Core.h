#ifndef CORE
#define CORE

#include <iostream>
#include <utility>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Properties.h"
#include "Scene.h"
#include "Render.h"

class Core {
public:
	Core(sf::ContextSettings _settings, bool& _go);
	void Setup();
	void Input();
	void Update();
	void PostUpdate();

private:
	int width = 800;
	int height = 600;

	bool go;
	Scene scene;
	Render render;
	Object input_comp;
	sf::Window window;
};

#endif