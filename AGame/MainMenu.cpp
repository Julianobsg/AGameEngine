#include "stdafx.h"
#include "MainMenu.h"
#include "Text.h"
#include "ButtonBehaviour.h"
#include "UIButton.h"
#include "Application.h"
#include <functional>


MainMenu::MainMenu()
{
	UIButton* playButton = new UIButton("Play", Vector2D<float>(5, 7));
	playButton->SetConclick(std::bind(&MainMenu::LoadLevel, this));
	this->AddGameObject(playButton->Button());

	UIButton* quitButton = new UIButton("Quit", Vector2D<float>(5, 7.5));;
	quitButton->SetConclick(std::bind(&MainMenu::QuitGame, this));
	this->AddGameObject(quitButton->Button());

}


MainMenu::~MainMenu()
{
}

void MainMenu::LoadLevel()
{
	Application::LoadScene(1);
}

void MainMenu::QuitGame()
{
	Application::CloseGame();
}
