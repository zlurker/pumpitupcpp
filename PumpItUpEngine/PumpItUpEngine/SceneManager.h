#pragma once
#include "ObjectList.h"
#include "RenderEngine.h"

class Scene;

class SceneManager
{
public: 
	SceneManager(ObjectList*, RenderEngine*);
	void SetScene(Scene* scene);
	void SceneManagerLogic();

private:
	Scene* currentScene;
	ObjectList* objectList;
	RenderEngine* renderEngine;

	std::mutex sceneMutex;
};

