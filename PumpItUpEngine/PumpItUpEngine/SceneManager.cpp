#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager(ObjectList* oL, RenderEngine* rE) {
	objectList = oL;
	renderEngine = rE;
}

void SceneManager::SetScene(Scene* scene) {
	std::lock_guard<std::mutex> guard(sceneMutex);
	currentScene = scene;
	objectList->ClearAllObjects();

	currentScene->SetSceneDependencies(objectList, renderEngine, this);
	currentScene->OnLevelLoaded();
}

void SceneManager::SceneManagerLogic() {
	while (true) {
		if (currentScene != nullptr) {
			currentScene->OnUpdate();
		}
	}
}