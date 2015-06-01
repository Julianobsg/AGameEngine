#include "stdafx.h"
#include "Ship.h"
#include "ShipBehaviour.h"
#include "Shot.h"
#include "Collision.h"


Ship::Ship()
{
	this->name = "main_ship";
	this->SetupAnimations();
	this->AddBehaviour(new ShipBehaviour);
	Collision* coll = new Collision;
	coll->tag = "Player";
	this->AddBehaviour(coll);
	this->transform->position.x = 5;
	this->transform->position.y = 8;
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

void Ship::Shoot()
{
	Vector2D<float> shootingPosition = Vector2D<float>(this->transform->position.x + 1, 
		this->transform->position.y - 0.1);
	currentScene->AddGameObject(new Shot(shootingPosition));
}
