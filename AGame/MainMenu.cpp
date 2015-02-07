#include "stdafx.h"
#include "MainMenu.h"
#include "Text.h"
#include "ButtonBehaviour.h"


MainMenu::MainMenu()
{
	Text* playButton = new Text("CaviarDreams.ttf");
	playButton->content = "Play";
	playButton->ChangeColor(0, 255, 255);
	playButton->AddBehaviour(new ButtonBehaviour);
	this->AddGameObject(playButton);
}


MainMenu::~MainMenu()
{
}
