#pragma once
#include "ObjectList.h"

class RenderEngine
{
public:
	RenderEngine(ObjectList* objectListSingletonInst);
	void render();

private:
	ObjectList* objectListSingleton;
};

