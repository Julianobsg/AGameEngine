#include "stdafx.h"
#include "IAMovement.h"
#include "Timer.h"
#include "Debug.h"


IAMovement::IAMovement()
{
	speed = 2.0f;
}


IAMovement::~IAMovement()
{
}

void IAMovement::Init()
{
}

void IAMovement::Update()
{
	float speedModifier = speed * Timer::deltaTime;

	this->transform->position.y += speedModifier;
}
