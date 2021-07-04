#ifndef COMPONENT
#define COMPONENT

#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../math/vec3.h"
#include "../Properties.h"
#include "../InputManager.h"
#include "../Texture.h"
#include "../Camera.h"
#include "../Shader.h"
#include "../Light.h"
#include "../Cube.h"
#include "../Skybox.h"

class Component {
public:
    Component() = default;

    void StartInput(bool& go);
    void Setup(unsigned int id);
    void Draw(unsigned int id);
    void UpdateLight(unsigned int id);

    std::map<unsigned int, std::shared_ptr<Shader>> shaders;
    std::map<unsigned int, std::shared_ptr<Light>> light;
    std::map<unsigned int, std::shared_ptr<Cube>> cubes;
    std::map<unsigned int, vec3> positions;
    std::shared_ptr<Skybox> skybox;

    sf::Event window_event;
    InputManager input_manager;

    Camera camera;
    vec3 cameraFront;
    vec3 cameraPos;
    vec3 cameraUp;

    Properties directional;
    Properties point;
    Properties spot;
    float cutOff = 12.0f;
    float outerCutOff = 15.0f;
    float constant = 1.0f;
    float linear = 0.09f;
    float quadratic = 0.032f;
    float shininess = 32.0f;

    Texture box;
    Texture cube;
};

#endif