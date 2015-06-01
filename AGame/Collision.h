#pragma once
#include "Behaviour.h"

class Collision
	: public Behaviour
{
public:
	string tag;
	Collision();
	~Collision();
	virtual void CollisionEnter(Collision* other);
};

