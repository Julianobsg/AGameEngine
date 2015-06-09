#include "stdafx.h"
#include "Enemy.h"
#include "IAMovement.h"


Enemy::Enemy(GameActionObserver* action)
{
	this->action = action;
	this->name = "Enemy";
	this->transform->position = Vector2D<float>(5, 5);
	this->AddTexture("tomatoes01.png");

	for (int i = 0; i < 15; i++)
	{
		this->AddClip(ENEMY_SIZE_X * i, 0, ENEMY_SIZE_X, ENEMY_SIZE_Y);
	}
	for (int i = 0; i < 15; i++)
	{
		this->AddClip(ENEMY_SIZE_X * i, ENEMY_SIZE_Y, ENEMY_SIZE_X, ENEMY_SIZE_Y);
	}
	EnemyCollision* coll = new EnemyCollision;
	coll->tag = "Enemy";
	AddBehaviour(coll);
	AddBehaviour(new IAMovement);
}


Enemy::~Enemy()
{
}

void Enemy::Die()
{
	action->EnemyDestroyed();
	this->Destroy();
}
