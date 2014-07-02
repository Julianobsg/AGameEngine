#include "stdafx.h"
#include "Bat.h"


Bat::Bat(void)
{
}

Bat::~Bat(void)
{
}

void Bat::Update()
{
	transform->position.y +=1;
}
