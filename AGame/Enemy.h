#pragma once
#include "Sprite.h"
#include "EnemyCollision.h"

class Enemy : public Sprite
{
public:
	const int ENEMY_SIZE_X = 48;
	const int ENEMY_SIZE_Y = 48;
	int health;
	Enemy();
	~Enemy();
};

