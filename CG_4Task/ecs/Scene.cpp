#include "Scene.h"

void Scene::push_object(Object object) {
	objects.push_back(object);
}

std::vector<Object>& Scene::get_objects() {
	return objects;
}
