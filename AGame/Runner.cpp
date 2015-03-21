#include "stdafx.h"
#include "Runner.h"


Runner::Runner()
{
	this->name = "Runner";
	Animation* newAnimation = new Animation;
	newAnimation->AddTexture("robotBoy_run.png");

	this->AddAnimantion(newAnimation);
	for (int i = 0; i < 7; i ++)
	{
		this->AddClip(2048 * i / 7, 0, 2048 / 7, 360);
	}
	//for (int i = 0; i < 7; i++)
	//{
	//	this->AddClip(2048 * i/ 7, 360, 2048 / 7, 360);
	//}
}


Runner::~Runner()
{
}
