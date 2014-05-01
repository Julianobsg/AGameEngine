#include "EngineGlobal.h"
#include "Scene.h"


Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}

void Scene::AddGameObject(GameObject go)
{
	gameObjects.push_back(go);
}
