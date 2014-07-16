#include "stdafx.h"
#include "Bat.h"
#include "Keyboard.h"



Bat::~Bat(void)
{
}

void Bat::Update()
{
	if (Keyboard::KeyDown(KeyCode::down))
	{
		transform->position.y +=1;
	} else if (Keyboard::KeyDown(KeyCode::up))
	{
		flyingSound.Play();
		transform->position.y -=1;
	}
}

void Bat::Init()
{
	flyingSound = AGameEngine::Audio("Media/flapping.wav");
}

Bat::Bat(void)
{

}
