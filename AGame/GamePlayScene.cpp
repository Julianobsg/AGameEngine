//
//  GamePlayScene.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 18/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "GamePlayScene.h"
#include "Ship.h"
#include "Shot.h"

void GamePlayScene::Init()
{

	//Text* text = new Text("CaviarDreams.ttf");
	//text->content = "Hello World";
	//AddGameObject(text);


	InitializeUI();

	Ship* player = new Ship;
	AddGameObject(player);
	AddGameObject(new Shot(Vector2D<float>(5, 5)));
}

void GamePlayScene::InitializeUI()
{

}
