#include "stdafx.h"
#include "ShipBehaviour.h"
#include "Keyboard.h"


ShipBehaviour::ShipBehaviour()
{
	speed = 2;
	fireRate = 0.3f;
	actualRating = 0.0f;
}


ShipBehaviour::~ShipBehaviour()
{
}

void ShipBehaviour::Init()
{
	myShip = (Ship*) this->gameObject;
}

void ShipBehaviour::Update()
{
	float horizontal = HorizontalCheck();

	float vertical = VerticalCheck();

	Move(horizontal, vertical);

	if (Keyboard::KeyDown(KeyCode::space) && actualRating <= 0.0f)
	{
		myShip->Shoot();
		actualRating = fireRate;
	}
	if (actualRating > 0)
	{
		actualRating -= (1 / Timer::framesPerSecond);
	}
}

void ShipBehaviour::Move(int horizontal, int vertical)
{
	float speedModifier = speed * Timer::deltaTime;
	
	this->transform->position.x += speedModifier * horizontal;
	this->transform->position.y += speedModifier * vertical;
}

float ShipBehaviour::HorizontalCheck()
{
	float horizontal = 0;
	if (Keyboard::KeyDown(KeyCode::left) && this->transform->position.x > -1)
	{
		myShip->Play(2);
		horizontal = -1;
	}
	else if (Keyboard::KeyDown(KeyCode::right) && this->transform->position.x < 10)
	{
		myShip->Play(1);
		horizontal = 1;
	}
	else
	{
		myShip->Play(0);
	}
	return horizontal;
}

float ShipBehaviour::VerticalCheck()
{
	float vertical = 0;
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

