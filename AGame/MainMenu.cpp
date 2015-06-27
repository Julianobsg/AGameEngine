#include "stdafx.h"
#include "MainMenu.h"
#include "ButtonBehaviour.h"
#include "Application.h"
#include <functional>


MainMenu::MainMenu()
{
	header = new Text("CaviarDreams.ttf");
	header->SetContent("Tomato attack");
	header->transform->position = Vector2D<float>(4, 2);

	playButton = new UIButton("Play", Vector2D<float>(5, 7));
	playButton->SetConclick(std::bind(&MainMenu::LoadLevel, this));

	quitButton = new UIButton("Quit", Vector2D<float>(5, 7.5));;
	quitButton->SetConclick(std::bind(&MainMenu::QuitGame, this));
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

void MainMenu::Init()
{
	this->AddGameObject(header);

	this->AddGameObject(playButton->Button());

	this->AddGameObject(quitButton->Button());
}
