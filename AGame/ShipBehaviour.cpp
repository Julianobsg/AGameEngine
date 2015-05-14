#include "stdafx.h"
#include "ShipBehaviour.h"
#include "Keyboard.h"


ShipBehaviour::ShipBehaviour()
{
}


ShipBehaviour::~ShipBehaviour()
{
}

void ShipBehaviour::Init()
{
	mySprite = (Sprite*) this->gameObject;
}

void ShipBehaviour::Update()
{
	if (Keyboard::KeyDown(KeyCode::left))
	{
		mySprite->Play(2);
		Move(-1, 0);
	}
	else if (Keyboard::KeyDown(KeyCode::right))
	{
		mySprite->Play(1);
		Move(1, 0);
	}
	else
	{
		mySprite->Play(0);
	}
}

void ShipBehaviour::Move(int vertical, int horizontal)
{
	this->transform->position.x += (vertical / Timer::framesPerSecond);
}


