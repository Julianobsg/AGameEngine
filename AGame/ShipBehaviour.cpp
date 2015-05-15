#include "stdafx.h"
#include "ShipBehaviour.h"
#include "Keyboard.h"


ShipBehaviour::ShipBehaviour()
{
	speed = 2;
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
	float horizontal = HorizontalCheck(horizontal);

	float vertical = VerticalCheck(vertical);

	Move(horizontal, vertical);

	/*if (Keyboard::KeyDown(KeyCode::space))
	{

	}*/
}

void ShipBehaviour::Move(int horizontal, int vertical)
{
	float speedModifier = speed * (1 / Timer::framesPerSecond);
	
	this->transform->position.x += speedModifier * horizontal;
	this->transform->position.y += speedModifier * vertical;
}

float ShipBehaviour::HorizontalCheck(float horizontal)
{

	if (Keyboard::KeyDown(KeyCode::left) && this->transform->position.x > 0)
	{
		mySprite->Play(2);
		horizontal = -1;
	}
	else if (Keyboard::KeyDown(KeyCode::right) && this->transform->position.x < 9)
	{
		mySprite->Play(1);
		horizontal = 1;
	}
	else
	{
		mySprite->Play(0);
	}
	return horizontal;
}

float ShipBehaviour::VerticalCheck(float vertical)
{
	if (Keyboard::KeyDown(KeyCode::down) && this->transform->position.y < 8.5)
	{
		vertical = 1;
	}
	else if (Keyboard::KeyDown(KeyCode::up) && this->transform->position.y > 0)
	{
		vertical = -1;
	}	
	return vertical;
}

