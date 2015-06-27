#pragma once
#include "Observer.h"
#include "Text.h"
#include "Ship.h"
class GameActionObserver :
	public Observer
{
public:
	Text* score;
	int scoreValue;
	float actualShipSpamRate;
	float spam;
	Ship* player;

	GameActionObserver();
	~GameActionObserver();

	virtual void Init();

	virtual void Update();
	void EnemyDestroyed();
};

