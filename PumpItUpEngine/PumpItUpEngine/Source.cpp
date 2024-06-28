#include "RenderEngine.h"
#include "ObjectList.h"
#include "FileLoader.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main() {


	ObjectList* objListSingleton = new ObjectList();
	FileLoader* fileLoaderSingleton = new FileLoader();
	fileLoaderSingleton->LoadSSCFiles();

	fs::path base_path = fs::current_path();
	std::cout << fs::current_path() << std::endl;
	std::string relative_arrow_path = "ArrowTextures";

	fs::path arrowFilePath = base_path / relative_arrow_path / "BASE 1x2.PNG";


	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(arrowFilePath.string())) {
		std::cerr << "Failed to load image" << std::endl;
		return 0;
	}

	objListSingleton->AddObject(new Object(0, 0, texture));
	objListSingleton->AddObject(new Object(100, 100, texture));
	objListSingleton->AddObject(new Object(200, 200, texture));
	objListSingleton->AddObject(new Object(300, 300, texture));

	RenderEngine render = RenderEngine(objListSingleton);
	render.render();
		
	return 0;
}