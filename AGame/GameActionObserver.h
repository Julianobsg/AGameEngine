#pragma once
#include "Observer.h"
#include "Text.h"
class GameActionObserver :
	public Observer
{
public:
	Text* score;
	int scoreValue;
	GameActionObserver();
	~GameActionObserver();

	virtual void Init();

	virtual void Update();
	void EnemyDestroyed();
};

