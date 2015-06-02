#include "stdafx.h"
#include "GameActionObserver.h"
#include "GamePlayScene.h"
#include <list>


GameActionObserver::GameActionObserver()
{
}


GameActionObserver::~GameActionObserver()
{
}

void GameActionObserver::Init()
{
	scoreValue = 0;
}

void GameActionObserver::Update()
{
}

void GameActionObserver::EnemyDestroyed()
{
	scoreValue++;
	score->SetContent(std::to_string(scoreValue));
}
