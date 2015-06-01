#pragma once
#include "Behaviour.h"
#include "Collision.h"
#include "Enemy.h"

class EnemyCollision :
	public Collision
{
public:
	EnemyCollision();
	~EnemyCollision();
	virtual void Init();

	virtual void Update();

	void CollisionEnter(Collision* other) override;
};

