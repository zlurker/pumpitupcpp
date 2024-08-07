#include "RenderEngine.h"
#include "ObjectList.h"
#include "FileLoader.h"
#include <filesystem>
#include <iostream>
#include "SSCLevelParser.h"
#include "GameLevel.h"
#include "SceneManager.h"
#include "GameLevelScene.h"
#include "TextureManager.h"
#include "RatioRect.h"
namespace fs = std::filesystem;

int main() {


	ObjectList objListSingleton;
	FileLoader* fileLoaderSingleton = new FileLoader();
	fileLoaderSingleton->LoadSSCFiles();

	fs::path base_path = fs::current_path();
	std::cout << fs::current_path() << std::endl;
	std::string relative_arrow_path = "ArrowTextures";

	fs::path sequenceZoneFilePath = base_path / relative_arrow_path / "BASE 1x2.PNG";
	fs::path blueArrowFilePath = base_path / relative_arrow_path / "DownLeft Tap Note 6x1.png";
	fs::path redArrowFilePath = base_path / relative_arrow_path / "UpLeft Tap Note 6x1.png";
	fs::path centerNoteFilePath = base_path / relative_arrow_path / "Center Tap Note 6x1.png";

	TextureManager textureManager;
	textureManager.AddTexture("base", sequenceZoneFilePath);
	textureManager.AddTexture("bluearrow", blueArrowFilePath);
	textureManager.AddTexture("redarrow", redArrowFilePath);
	textureManager.AddTexture("center", centerNoteFilePath);

	GameLevel gameLevel;
	SSCLevelParser sscLevelParser;
	SSCFile* sscFile = fileLoaderSingleton->GetSSCFile(0);
	SSCFileLevels* sscFileLevel = sscFile->GetLevel(0);

	sscLevelParser.ParseFile(sscFile->GetSSCFullPath(), sscFileLevel->GetCharStart(), sscFileLevel->GetCharEnd());

	RenderEngine render = RenderEngine(&objListSingleton);

	std::thread renderThread([&render]() {
		render.render();
		});

	std::cout << "Render logic is up." << std::endl;

	SceneManager sceneManager(&objListSingleton, &render, &textureManager);

	std::thread sceneManagementThread([&sceneManager]() {
		sceneManager.SceneManagerLogic();
		});
	std::cout << "Scene Management Logic is up." << std::endl;

	GameLevelScene gameLevelScene;
	sceneManager.SetScene(&gameLevelScene);

	/*objListSingleton.AddObject(Object(0, 0, blueArrowTexture, bottomLeftArrowRect));
	objListSingleton.AddObject(Object(50, 0, redArrowTexture, topLeftArrowRect));
	objListSingleton.AddObject(Object(100, 0, centerNoteTexture, centerNoteRect));
	objListSingleton.AddObject(Object(150, 0, redArrowTexture, topRightArrowRect));
	objListSingleton.AddObject(Object(200, 0, blueArrowTexture, bottomRightArrowRect));*/
	RatioRect sequenceZoneRatio(0, 0, 1, 0.5f);
	objListSingleton.AddObject(Object(0, 0, textureManager.GetTextureData("base"), &sequenceZoneRatio));
	// Wait for the threads to complete
	renderThread.join();
	sceneManagementThread.join();

	std::cout << "Main thread finished." << std::endl;
	return 0;
}