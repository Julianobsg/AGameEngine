#include "stdafx.h"

#include "MainGame.h"
#include "MainMenu.h"


MainGame::MainGame(void)
{
}

MainGame::~MainGame(void)
{
}

void MainGame::Init()
{
	//this->application = application;
	MainMenu menu;
	menu.name = "MainMenu";

	GamePlayScene scene1;
	scene1.name = "Scene 1";
    scene1.Init();
    
    Application::SetScreenSize(Vector2D<int>(720, 640));
	Application::AddScene(menu);
	Application::AddScene(scene1);

}


int MainGame::Run()
{
	return Application::Run();
}