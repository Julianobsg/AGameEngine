#include "stdafx.h"
#include "Fall.h"


Fall::Fall(void)
{
}

Fall::~Fall(void)
{
}

void Fall::Update()
{
	transform->position.y +=1;
}
