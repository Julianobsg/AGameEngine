#include "stdafx.h"

#include "MainGame.h"
#include "MainMenu.h"
#include "EndGameScene.h"


MainGame::MainGame(void)
{
}

MainGame::~MainGame(void)
{
}

void MainGame::Init()
{
	MainMenu* menu = new MainMenu;
	menu->name = "MainMenu";

	GamePlayScene* scene1 = new GamePlayScene;
	scene1->name = "Gameplay";
    
	EndGameScene* endGame = new EndGameScene;
	endGame->name = "EndGame";

    Application::SetScreenSize(Vector2D<int>(720, 640));
	Application::AddScene(menu);
	Application::AddScene(scene1);
	Application::AddScene(endGame);

}


int MainGame::Run()
{
	return Application::Run();
}