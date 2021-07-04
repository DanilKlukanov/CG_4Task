#ifndef SCENE
#define SCENE

#include <vector>

#include "Object.h"

class Scene {
public:
	void push_object(Object object);
	std::vector<Object>& get_objects();

private:
	std::vector<Object> objects;
};

#endif