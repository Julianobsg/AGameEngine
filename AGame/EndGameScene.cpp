#include "stdafx.h"
#include "EndGameScene.h"
#include "Text.h"
#include "Vector2D.h"
#include "UIButton.h"
#include "Application.h"


EndGameScene::EndGameScene()
{

}


EndGameScene::~EndGameScene()
{
}

void EndGameScene::LoadGameplay()
{
	Application::LoadScene(1);
}

void EndGameScene::LoadMainMenu()
{
	Application::LoadScene(0);
}

void EndGameScene::Init()
{
	Text* header = new Text("CaviarDreams.ttf");
	header->SetContent("Game Over");
	header->transform->position = Vector2D<float>(5, 2);
	Text* scoreText = new Text("CaviarDreams.ttf");
	scoreText->SetContent("Score:" + to_string(score));
	scoreText->transform->position = Vector2D<float>(5, 3);

	UIButton* playAgain = new UIButton("Play Again", Vector2D<float>(5, 7));
	playAgain->SetConclick(std::bind(&EndGameScene::LoadGameplay, this));
	this->AddGameObject(playAgain->Button());

	UIButton* mainMenu = new UIButton("Back to menu", Vector2D<float>(5, 7.5));;
	mainMenu->SetConclick(std::bind(&EndGameScene::LoadMainMenu, this));
	this->AddGameObject(mainMenu->Button());

	this->AddGameObject(header);
	this->AddGameObject(scoreText);
}
