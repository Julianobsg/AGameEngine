#pragma once
#include <list>
#include "GameObject.h"

class Observer
{
public:
	Scene* currentScene;
	Observer();
	~Observer();
	virtual void Init();
	virtual void Update();
private:
	void Load(list<GameObject*> gameObjects);
};

