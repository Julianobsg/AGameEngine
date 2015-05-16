#include "stdafx.h"
#include "Shot.h"
#include "ShotBehaviour.h"


Shot::Shot(Vector2D<float> position)
{
	this->transform->position = position;
	
	this->AddTexture("effects01.png");
	for (int i = 0; i < 4; i ++)
	{
		this->AddClip(SHOT_SIZE * i, 0, SHOT_SIZE, SHOT_SIZE);
	}
	this->AddBehaviour(new ShotBehaviour);
}


Shot::~Shot()
{

}

