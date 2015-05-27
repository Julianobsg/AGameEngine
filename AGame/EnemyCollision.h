#pragma once
#include "Behaviour.h"
#include "Collision.h"

class EnemyCollision :
	public Collision
{
public:
	EnemyCollision();
	~EnemyCollision();

	virtual void Init();

	virtual void Update();

	virtual void CollisionEnter();

};

