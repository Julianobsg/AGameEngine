#include "stdafx.h"

#include "MainGame.h"


MainGame::MainGame(void)
{
	this->application = new Application();
}

MainGame::~MainGame(void)
{
	delete(application);
}

void MainGame::Init()
{
	//this->application = application;
	Scene scene1;
	scene1.name = "Scene 1 ";
	Sprite* helloWorld = new Sprite;
	helloWorld->name = "Hello World";
	//Sprite helloWorld = Sprite("Hello World");
	helloWorld->SetTexture("helloworld.jpg");
	scene1.AddGameObject(helloWorld);
	scene1.AddGameObject(helloWorld);

	GameObject* go = new Sprite;
	
	Sprite* sprite = dynamic_cast<Sprite*>(go);
	if (sprite != NULL)
	{
		sprite->texture = "TESTE";
	}
	application->AddScene(scene1);

}


int MainGame::Run()
{
	return application->Run();
}