#pragma once
#include "Scene.h"
class GameLevelScene :
    public Scene
{
public:
    GameLevelScene();
    virtual void OnLevelLoaded();
    virtual void OnUpdate();
};