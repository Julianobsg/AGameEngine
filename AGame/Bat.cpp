#include "stdafx.h"
#include "Bat.h"

void Bat::Init()
{
    this->name = "batafire";
	BatController* fall = new BatController();
    Animation* newAnimation = new Animation;
    newAnimation->AddTexture("batafire-spritesheet.png");
    
    this->AddAnimantion(newAnimation);
	this->LastTexture()->Clip(0, 0, 70, 75);
	this->AddClip(75 , 0, 75, 75);
	this->AddClip(180, 0, 75, 75);
	this->AddClip(280, 0, 75, 75);
	this->AddClip(370, 0, 75, 75);
	this->AddClip(440, 0, 75, 75);
	this->AddClip(75 , 110, 75, 75);
	this->AddClip(180, 110, 75, 75);
	this->AddClip(280, 110, 75, 75);
	this->AddClip(370, 110, 75, 75);
	//bat->AddClip(440, 110, 75, 75);
	this->transform->scale.x = -1;
	this->AddBehaviour(fall);
}