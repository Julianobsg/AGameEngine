#include "Touch.h"

Touch::Touch()
{
	isTouching = false;
	isMoving = true;
	
	touchInstance = this;
}


Touch::~Touch()
{
}

void Touch::SetEvent(SDL_Event* e)
{
	if (e->type == SDL_FINGERDOWN)
	{
		Instance()->isTouching = true;
	}
	if (e->type == SDL_FINGERMOTION)
	{
		Instance()->isMoving = true;
	}
	else
	{
		Instance()->isMoving = false;
	}
	if (e->type == SDL_FINGERUP)
	{
		Instance()->isTouching = false;
	}
}

Touch* Touch::Instance()
{
	if (touchInstance == NULL)
	{
		touchInstance = new Touch;
	}
	return touchInstance;
}

Touch* Touch::touchInstance;
