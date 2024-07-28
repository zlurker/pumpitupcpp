#include "GameLevelScene.h"
#include <iostream>

GameLevelScene::GameLevelScene() {

}

void GameLevelScene::OnLevelLoaded() {
	std::cout << "Game started" << std::endl;
}

void GameLevelScene::OnUpdate() {
	std::cout << "Updating level" << std::endl;
}