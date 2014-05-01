#pragma once

#include "EngineGlobal.h"
#include "GameObject.h"
#include <list>

using namespace std;

class Scene
{
public:
	list<GameObject> gameObjects;

	Scene(void);
	~Scene(void);
	void AddGameObject(GameObject go);

	string name;
};

