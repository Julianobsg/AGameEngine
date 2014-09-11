#include "stdafx.h"

#include "MainGame.h"
#include "Bat.h"
#include "InfinityBackground.h"


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
	Sprite* bat = new Sprite;
	bat->name = "batafire";
	Bat* fall = new Bat();
    Animation* newAnimation = new Animation;
    newAnimation->AddTexture("Media/batafire-spritesheet.png");
    
    bat->AddAnimantion(newAnimation);
	bat->LastTexture()->Clip(0, 0, 70, 75);
	bat->AddClip(75 , 0, 75, 75);
	bat->AddClip(180, 0, 75, 75);
	bat->AddClip(280, 0, 75, 75);
	bat->AddClip(370, 0, 75, 75);
	bat->AddClip(440, 0, 75, 75);
	bat->AddClip(75 , 110, 75, 75);
	bat->AddClip(180, 110, 75, 75);
	bat->AddClip(280, 110, 75, 75);
	bat->AddClip(370, 110, 75, 75);
	//bat->AddClip(440, 110, 75, 75);
	bat->transform->scale.x = -1;
	bat->AddBehaviour(fall);

	Sprite* background = new Sprite;
	background->name = "background";
	background->AddTexture("Media/background.png");
	background->LastTexture()->Clip(10, 220, 510, 180);
	background->AddBehaviour(new InfinityBackground);

	Sprite* background2 = new Sprite;
	background2->name = "background";
	background2->AddTexture("Media/background.png");
	background2->LastTexture()->Clip(10, 220, 510, 180);
	background2->transform->position = Vector2D(500, 0);
	background2->AddBehaviour(new InfinityBackground);

	scene1.AddGameObject(background);
	scene1.AddGameObject(background2);
	scene1.AddGameObject(bat);

	application->AddScene(scene1);

}


int MainGame::Run()
{
	return application->Run();
}