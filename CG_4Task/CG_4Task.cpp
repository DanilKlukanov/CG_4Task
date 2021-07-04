#pragma once
//ecs
#include "ecs/Core.h"

int main() {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	bool go = true;
	Core core(settings, go);
	core.Setup();

	while (go) {
		core.Input();
		core.Update();
		core.PostUpdate();
	}
	return 0;
}
