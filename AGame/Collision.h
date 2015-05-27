#pragma once
#include "Behaviour.h"

class Collision
	: public Behaviour
{
public:
	Collision();
	~Collision();
	virtual void CollisionEnter();
};

