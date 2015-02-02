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
	GamePlayScene scene1;
	scene1.name = "Scene 1 ";
    scene1.Init();
    
    application->SetScreenSize(Vector2D<int>(720, 540));
	application->AddScene(scene1);

}


int MainGame::Run()
{
	return application->Run();
}