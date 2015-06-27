#include "stdafx.h"
#include "GameActionObserver.h"
#include "GamePlayScene.h"
#include <list>
#include "Enemy.h"
#include "Application.h"
#include "EndGameScene.h"


GameActionObserver::GameActionObserver()
{
	spam = 3.0f;
	actualShipSpamRate = spam;
}


GameActionObserver::~GameActionObserver()
{
}

void GameActionObserver::Init()
{
	scoreValue = 0;
	list<GameObject*> gos = this->currentScene->gameObjects;
	for (std::list<GameObject*>::iterator it = gos.begin(); it != gos.end(); it++)
	{
		if ((*it)->name == "main_ship")
		{
			player = static_cast<Ship*> (*it);
		}
	}
}

void GameActionObserver::Update()
{
	if (!player->alive)
	{
		EndGameScene* egs = (EndGameScene*) Application::GetScene("EndGame");
		egs->score = scoreValue;
		Application::LoadScene("EndGame");
	}
	if (actualShipSpamRate <= 0)
	{
		Enemy* enemy = new Enemy(this);
		float randomX = rand() % 10;
		enemy->transform->position = Vector2D<float>(randomX, 0.0f);

		this->currentScene->AddGameObject(enemy);
		actualShipSpamRate = spam;
	}
	if (actualShipSpamRate > 0)
	{
		actualShipSpamRate -= (1 / Timer::framesPerSecond);
	}
}

void GameActionObserver::EnemyDestroyed()
{
	scoreValue++;
	score->SetContent(std::to_string(scoreValue));
}
