#pragma once
#include "Sprite.h"
#include "EnemyCollision.h"
#include "GameActionObserver.h"

class Enemy : public Sprite
{
public:
	const int ENEMY_SIZE_X = 48;
	const int ENEMY_SIZE_Y = 48;
	int health;
	GameActionObserver* action;
	Enemy(GameActionObserver* action);
	~Enemy();
	void Die();
};

