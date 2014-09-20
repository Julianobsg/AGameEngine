//
//  GamePlayer.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 18/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "GamePlayScene.h"

void GamePlayScene::Init()
{
    Sprite* bat = new Sprite;
	bat->name = "batafire";
	Bat* fall = new Bat();
    Animation* newAnimation = new Animation;
    newAnimation->AddTexture("batafire-spritesheet.png");
    
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
	background->AddTexture("background.png");
	background->LastTexture()->Clip(10, 220, 510, 180);
	background->AddBehaviour(new InfinityBackground);
	
    Sprite* background2 = new Sprite;
	background2->name = "background";
	background2->AddTexture("background.png");
	background2->LastTexture()->Clip(10, 220, 510, 180);
	background2->transform->position = Vector2D(500, 0);
	background2->AddBehaviour(new InfinityBackground);
    
	AddGameObject(background);
	AddGameObject(background2);
	AddGameObject(bat);

}