#include "Application.h"
#include <thread>         // std::thread

Application::Application(void)
{
	currentScene = 0;
}


Application::~Application(void)
{
}


void Application::Run()
{
	list<GameObject*> sceneObjects = scenes[currentScene].gameObjects;
	/*for (std::list<GameObject>::iterator it = sceneObjects.begin(); it != sceneObjects.end(); it++) 
	{
	it->Update();
	Draw(*it);
	}*/
}

void Application::AddScene(Scene scene)
{
	scenes.push_back(scene);
}

void Application::Update()
{

}

void Application::Draw(GameObject go)
{
	printf("%s", go.name);
}
