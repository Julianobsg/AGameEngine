#pragma once
#include "Behaviour.h"
class IAMovement :
	public Behaviour
{
public:
	float speed;

	IAMovement();
	~IAMovement();

	virtual void Init();

	virtual void Update();
};

