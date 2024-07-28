#include "RenderEngine.h"
#include "ObjectList.h"
#include "FileLoader.h"
#include <filesystem>
#include <iostream>
#include "SSCLevelParser.h"
#include "GameLevel.h"
namespace fs = std::filesystem;

sf::Texture* RetrieveTexture(const fs::path& arrowFilePath) {
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(arrowFilePath.string())) {
		std::cerr << "Failed to load image" << std::endl;
		return nullptr;
	}

	return texture;
}

sf::IntRect* GenerateRect(const sf::Texture& texture, int widthDivision, int heightDivision, bool mirrorX) {
	sf::Vector2u size = texture.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	int xMirrorMultiplier = mirrorX ? -1:1;

	sf::IntRect* rect = new sf::IntRect(mirrorX ? width:0, 0, xMirrorMultiplier * (width / widthDivision), height / heightDivision);
	return rect;
}

int main() {


	ObjectList* objListSingleton = new ObjectList();
	FileLoader* fileLoaderSingleton = new FileLoader();
	fileLoaderSingleton->LoadSSCFiles();

	fs::path base_path = fs::current_path();
	std::cout << fs::current_path() << std::endl;
	std::string relative_arrow_path = "ArrowTextures";

	fs::path sequenceZoneFilePath = base_path / relative_arrow_path / "BASE 1x2.PNG";

	sf::Texture* sequenceZoneTexture = RetrieveTexture(sequenceZoneFilePath);
	sf::IntRect* sequenceZoneRect = GenerateRect(*sequenceZoneTexture, 1, 2,false);

	fs::path blueArrowFilePath = base_path / relative_arrow_path / "DownLeft Tap Note 6x1.png";
	sf::Texture* blueArrowTexture = RetrieveTexture(blueArrowFilePath);
	sf::IntRect* bottomLeftArrowRect = GenerateRect(*blueArrowTexture, 6, 1,false);

	fs::path redArrowFilePath = base_path / relative_arrow_path / "UpLeft Tap Note 6x1.png";
	sf::Texture* redArrowTexture = RetrieveTexture(redArrowFilePath);
	sf::IntRect* topLeftArrowRect = GenerateRect(*redArrowTexture, 6, 1,false);

	fs::path centerNoteFilePath = base_path / relative_arrow_path / "Center Tap Note 6x1.png";
	sf::Texture* centerNoteTexture = RetrieveTexture(centerNoteFilePath);
	sf::IntRect* centerNoteRect = GenerateRect(*centerNoteTexture, 6, 1,false);

	sf::IntRect* topRightArrowRect = GenerateRect(*redArrowTexture, 6, 1, true);
	sf::IntRect* bottomRightArrowRect = GenerateRect(*blueArrowTexture, 6, 1, true);

	objListSingleton->AddObject(new Object(0, 0, blueArrowTexture, bottomLeftArrowRect));
	objListSingleton->AddObject(new Object(50, 0, redArrowTexture, topLeftArrowRect));
	objListSingleton->AddObject(new Object(100, 0, centerNoteTexture, centerNoteRect));
	objListSingleton->AddObject(new Object(150, 0, redArrowTexture, topRightArrowRect));
	objListSingleton->AddObject(new Object(200, 0, blueArrowTexture, bottomRightArrowRect));

	objListSingleton->AddObject(new Object(0, 0, sequenceZoneTexture, sequenceZoneRect));

	GameLevel gameLevel;
	SSCLevelParser sscLevelParser;
	SSCFile* sscFile = fileLoaderSingleton->GetSSCFile(0);
	SSCFileLevels* sscFileLevel = sscFile->GetLevel(0);

	sscLevelParser.ParseFile(sscFile->GetSSCFullPath(), sscFileLevel->GetCharStart(), sscFileLevel->GetCharEnd());

	RenderEngine render = RenderEngine(objListSingleton);
	render.render();

	return 0;
}