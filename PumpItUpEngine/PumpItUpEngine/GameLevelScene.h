#pragma once
#include "Scene.h"
class GameLevelScene :
    public Scene
{
public:
    GameLevelScene(ObjectList*);
    virtual void OnLevelLoaded();
    virtual void OnUpdate();
};