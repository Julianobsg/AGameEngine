//
//  GamePlayScene.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 18/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "GamePlayScene.h"
#include "Ship.h"
#include "Enemy.h"
#include "CollisionDetection.h"

void GamePlayScene::Init()
{
	Ship* player = new Ship;
	GameActionObserver* gameAction = new GameActionObserver;
	Text* score = new Text("CaviarDreams.ttf");
	score->SetContent("0000");
	score->name = "score";
	gameAction->score = score;

	AddGameObject(score);
	AddGameObject(player);
	AddObserver(new CollisionDetection);
	AddObserver(gameAction);
}

void GamePlayScene::InitializeUI()
{
	
}

GamePlayScene::GamePlayScene()
{

}
