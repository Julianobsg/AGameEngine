#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
	this->name = "main_ship";
	this->SetupAnimations();
}


Ship::~Ship()
{
}

void Ship::SetupAnimations()
{
	
	Animation* frontAnimation = new Animation;
	frontAnimation->AddTexture(("fox01.png"));
	//for (int i = 0; i < 4; i++)
	//{
	//	frontAnimation->AddClip(i * SHIP_WIDTH, 250, SHIP_WIDTH, SHIP_HEIGHT);
	//}

	for (int i = 12; i < 16; i++)
	{
		this->AddClip(i * SHIP_WIDTH, 250, SHIP_WIDTH, SHIP_HEIGHT);
	}

	for (int i = 8; i < 12; i++)
	{
		this->AddClip(i * SHIP_WIDTH, 370, SHIP_WIDTH, SHIP_HEIGHT);
	}
	this->AddAnimantion(frontAnimation);
}
