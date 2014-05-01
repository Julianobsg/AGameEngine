#include "stdafx.h"

#include "MainGame.h"


MainGame::MainGame(Application* app)
{
	this->application = app;
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
	Sprite helloWorld = Sprite("Hello World");
	helloWorld.SetTexture("helloworld.jpg");
	scene1.AddGameObject(helloWorld);

	application->AddScene(scene1);

}