#pragma once

#include "EngineGlobal.h"
#include "GameObject.h"
#include <list>
#include "Observer.h"
#include "Camera.h"

using namespace std;

class Scene
{
	friend class Application;
public:
	//TODO change list to vector, check if really is better for processing;
	list<GameObject*> gameObjects;
	list<Observer*> observers;

	Scene(void);
	~Scene(void);
	void AddGameObject(GameObject* go);
	void AddObserver(Observer* observer);
	string name;
private:
	void Load(SDL_Renderer* renderer);
	void Unload();
	void Update();

	void Draw(Camera* mainCamera);
	SDL_Renderer* renderer;
};

