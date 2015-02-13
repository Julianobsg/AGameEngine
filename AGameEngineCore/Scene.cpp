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
	gameObjects.push_back(go);
}

void Scene::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Scene::Load(SDL_Renderer* renderer)
{
	GameObject* go;

	for (std::list<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
	{
		Observer ob = **it;
		ob.Init();
	}

	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		go = *it;

		Sprite* sprite = dynamic_cast<Sprite*>(go);
		Text* text = dynamic_cast<Text*>(go);

		if (sprite != NULL)
		{
			sprite->Load(renderer);
		}
		else if (text != NULL)
		{
			text->Load(renderer);
		}

		go->Init();
	}
}

void Scene::Update()
{
	for (std::list<Observer*>::iterator it = observers.begin(); it != observers.end(); it++)
	{
		Observer ob = **it;
		ob.Update();
	}

	GameObject* go;

	for (std::list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		go = *it;
		go->Update();
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
