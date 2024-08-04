#pragma once
#include "ObjectList.h"
#include "RenderEngine.h"
#include "TextureManager.h"

class Scene;

class SceneManager
{
public: 
	SceneManager(ObjectList*, RenderEngine*, TextureManager*);
	void SetScene(Scene* scene);
	void SceneManagerLogic();

private:
	Scene* currentScene;
	ObjectList* objectList;
	RenderEngine* renderEngine;
	TextureManager* textureManager;

	std::mutex sceneMutex;
};

