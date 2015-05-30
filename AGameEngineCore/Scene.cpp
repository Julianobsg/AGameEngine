#include "EngineGlobal.h"
#include "Scene.h"
#include "Text.h"
#include "Sprite.h"

Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}

void Scene::AddGameObject(GameObject* go)
{
	gameObjects.emplace_back(go);
	if (renderer != NULL)
	{
		go->Load(renderer);
		go->Init();
		go->currentScene = this;
	}
}

void Scene::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Scene::Load(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	for (std::list<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
	{
		Observer* ob = *it;
		ob->currentScene = this;
		ob->Init();
	}

	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		GameObject* go;
		go = *it;
		go->Load(renderer);
		
		go->currentScene = this;
		go->Init();
	}
}

void Scene::Update()
{
	for (std::list<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
	{
		Observer* ob = *it;
		ob->Update();
	}

	GameObject* go = NULL;

	list<GameObject*> tempList = gameObjects;
	//Temp to avoid invalidation in list of gameobjects in resiging it
	for (std::list<GameObject*>::iterator it = tempList.begin(); it != tempList.end(); it++)
	{
		(*it)->Update();
		if ((*it)->destroy) 
		{
			gameObjects.remove((*it));
			delete(*it);
		}
	}
}


void Scene::Draw(Camera* mainCamera)
{

	GameObject* go;

	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		go = *it;
		if (go != NULL)
		{
			mainCamera->Draw(go);
		}

	}
}

void Scene::Unload()
{

	GameObject* go;

	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		go = *it;
		Sprite* sprite = dynamic_cast<Sprite*>(go);
		if (sprite != NULL)
		{
			sprite->Destroy();
		}
	}
}
