//
//  GamePlayer.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 18/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "GamePlayScene.h"
#include "Bat.h"

void GamePlayScene::Init()
{

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
    

    Bat* bat = new Bat;
    
    bat->Init();
    bat->transform->position.x = i;
    
    AddGameObject(bat);

    
}