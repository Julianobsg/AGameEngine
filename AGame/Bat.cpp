#include "stdafx.h"
#include "Bat.h"
#include "Keyboard.h"


Bat::Bat(void)
{
}

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
		transform->position.y -=1;
	}
}
