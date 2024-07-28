#pragma once
#include "ObjectList.h"
#include "RenderEngine.h"

class SceneManager;

class Scene
{
public:
	void SetSceneDependencies(ObjectList*, RenderEngine*, SceneManager*);

	virtual void OnLevelLoaded();
	virtual void OnUpdate();

private:
	ObjectList* objectList;
	RenderEngine* renderEngine;
	SceneManager* sceneManager;
};