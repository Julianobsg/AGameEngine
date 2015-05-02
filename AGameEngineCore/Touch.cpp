#include "Touch.h"
#include "Application.h"

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
		Instance()->AddFinger(e->tfinger);
	}
	if (e->type == SDL_FINGERMOTION)
	{
		Instance()->isMoving = true;
		Instance()->MoveFinger(e->tfinger);
	}
	else
	{
		Instance()->isMoving = false;
	}
	if (e->type == SDL_FINGERUP)
	{
		Instance()->isTouching = false;
		Instance()->RemoveFinger(e->tfinger);
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

Finger* Touch::GetFinger(int index)
{
	return Instance()->fingers[index];
}

void Touch::AddFinger(SDL_TouchFingerEvent e)
{
	Finger* finger = new Finger;
	finger->id = e.fingerId;
	Vector2D<int> screenSize = Application::GetScreenSize();
	finger->position = new Vector2D<int>(e.x * screenSize.x, e.y * screenSize.y);
	fingers.insert(std::pair<int, Finger*>(e.fingerId, finger));
}

void Touch::MoveFinger(SDL_TouchFingerEvent e)
{
	Vector2D<int> screenSize = Application::GetScreenSize();
	fingers[e.fingerId]->position = new Vector2D<int>(e.x * screenSize.x, e.y * screenSize.y);
}

void Touch::RemoveFinger(SDL_TouchFingerEvent e)
{
	fingers.erase(e.fingerId);
}

Touch* Touch::touchInstance;
