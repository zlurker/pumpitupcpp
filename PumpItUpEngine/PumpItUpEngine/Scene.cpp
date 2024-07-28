#include "Scene.h"
#include "SceneManager.h"

void Scene::SetSceneDependencies(ObjectList* oL, RenderEngine* rE, SceneManager* sM) {
	objectList = oL;
	renderEngine = rE;
	sceneManager = sM;
}

void Scene::OnLevelLoaded() {

}

void Scene::OnUpdate() {

}