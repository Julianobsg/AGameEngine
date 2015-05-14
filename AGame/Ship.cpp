#include "stdafx.h"
#include "Ship.h"
#include "ShipBehaviour.h"


Ship::Ship()
{
	this->name = "main_ship";
	this->SetupAnimations();
	this->AddBehaviour(new ShipBehaviour);
}


Ship::~Ship()
{
}

void Ship::SetupAnimations()
{
	Animation* frontAnimation = new Animation;
	frontAnimation->AddTexture(("fox01.png"));
	for (int i = 0; i < 4; i++)
	{
		frontAnimation->AddClip(i * SHIP_WIDTH, 250, SHIP_WIDTH, SHIP_HEIGHT);
	}

	Animation* leftAnimation = new Animation;
	leftAnimation->AddTexture(frontAnimation->LastTexture());

	for (int i = 12; i < 16; i++)
	{
		leftAnimation->AddClip(i * SHIP_WIDTH, 250, SHIP_WIDTH, SHIP_HEIGHT);
	}


	Animation* rightAnimation = new Animation;
	rightAnimation->AddTexture(frontAnimation->LastTexture());

	for (int i = 8; i < 12; i++)
	{
		rightAnimation->AddClip(i * SHIP_WIDTH, 370, SHIP_WIDTH, SHIP_HEIGHT);
	}
	this->AddAnimantion(frontAnimation);
	this->AddAnimantion(leftAnimation);
	this->AddAnimantion(rightAnimation);
}
