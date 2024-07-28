#pragma once
#include "ObjectList.h"

class Scene
{
public:
	Scene(ObjectList*);

	virtual void OnLevelLoaded();
	virtual void OnUpdate();

private:
	ObjectList* objectList;
};