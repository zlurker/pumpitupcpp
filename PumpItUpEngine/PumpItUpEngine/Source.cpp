#include "RenderEngine.h"
#include "ObjectList.h"
#include <iostream>

int main() {
	
	sf::Texture texture;
	if (!texture.loadFromFile("../ArrowTextures/BASE 1x2.PNG")) {
		std::cerr << "Failed to load image" << std::endl;
		return 0;
	}

	ObjectList::AddObject(new Object(0, 0, texture));
	RenderEngine render;
	render.render();
		
	return 0;
}