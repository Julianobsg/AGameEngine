#pragma once
#include "Behaviour.h"
class EnemyCollision :
	public Behaviour
{
public:
	EnemyCollision();
	~EnemyCollision();

	virtual void Init();

	virtual void Update();

};

