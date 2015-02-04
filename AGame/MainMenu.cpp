#include "stdafx.h"
#include "MainMenu.h"
#include "Text.h"


MainMenu::MainMenu()
{
	Text* playButton = new Text("CaviarDreams.ttf");
	playButton->content = "Play";
	playButton->ChangeColor(0, 255, 255);
	this->AddGameObject(playButton);
}


MainMenu::~MainMenu()
{
}
