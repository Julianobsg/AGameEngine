#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	this->AddTexture("tomatoes01.png");

	for (int i = 0; i < 15; i++)
	{
		this->AddClip(ENEMY_SIZE_X * i, 0, ENEMY_SIZE_X, ENEMY_SIZE_Y);
	}
	for (int i = 0; i < 15; i++)
	{
		this->AddClip(ENEMY_SIZE_X * i, ENEMY_SIZE_Y, ENEMY_SIZE_X, ENEMY_SIZE_Y);
	}
}


Enemy::~Enemy()
{
}
