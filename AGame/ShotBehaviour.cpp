#include "stdafx.h"
#include "ShotBehaviour.h"
#include "Timer.h"


ShotBehaviour::ShotBehaviour()
{
	speed = 5 / Timer::framesPerSecond;
}


ShotBehaviour::~ShotBehaviour()
{
}

void ShotBehaviour::Init()
{
	myShot = (Shot*) this->gameObject;

}

void ShotBehaviour::Update()
{
	this->transform->position.y -= speed;
	if (this->transform->position.y < 0)
	{
		myShot->Destroy();
	}
}
