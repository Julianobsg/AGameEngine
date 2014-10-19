#include "Touch.h"


Touch::Touch()
{
	isTouching = false;
}


Touch::~Touch()
{
}

void Touch::SetTouch(SDL_Event* e)
{
	if (e->type == SDL_FINGERDOWN)
	{
		isTouching = true;
	}
	if (e->type == SDL_FINGERMOTION)
	{

	}
	if (e->type == SDL_FINGERUP)
	{
		isTouching = false;
	}
}
