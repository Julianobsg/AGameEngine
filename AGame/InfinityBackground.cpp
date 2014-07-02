#include "stdafx.h"
#include "InfinityBackground.h"


InfinityBackground::InfinityBackground(void)
{
}


InfinityBackground::~InfinityBackground(void)
{
}

void InfinityBackground::Update()
{
	transform->position.x -= 1;
	if (transform->position.x + texture->size.x < 0)
	{
		transform->position.x = texture->size.x;
	}
}
