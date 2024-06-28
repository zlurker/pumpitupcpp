#include "RenderEngine.h"
#include "ObjectList.h"
#include "FileLoader.h"
#include <iostream>

int main() {
	
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("../ArrowTextures/BASE 1x2.PNG")) {
		std::cerr << "Failed to load image" << std::endl;
		return 0;
	}

	ObjectList* objListSingleton = new ObjectList();
	FileLoader* fileLoaderSingleton = new FileLoader();
	fileLoaderSingleton->LoadSSCFiles();

	objListSingleton->AddObject(new Object(0, 0, texture));
	objListSingleton->AddObject(new Object(100, 100, texture));
	objListSingleton->AddObject(new Object(200, 200, texture));
	objListSingleton->AddObject(new Object(300, 300, texture));

	RenderEngine render = RenderEngine(objListSingleton);
	render.render();
		
	return 0;
}