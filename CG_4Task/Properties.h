#ifndef PROP
#define PROP

#include <iostream>
#include "math/vec3.h"

class Properties {
public:
	Properties() {}

	Properties(vec3 _ambient, vec3 _diffuse, vec3 _specular) {
		ambient = _ambient;
		diffuse = _diffuse;
		specular = _specular;
	}
	Properties(vec3 _direction, vec3 _ambient, vec3 _diffuse, vec3 _specular) {
		direction = _direction;
		ambient = _ambient;
		diffuse = _diffuse;
		specular = _specular;
	}

	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

#endif