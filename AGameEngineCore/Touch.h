#pragma once
#include "Input.h"
#include "EngineGlobal.h"
#include "Vector2D.h"
#include "Finger.h"

class Touch :
	public Input
{
	friend class Application;
public:
	static bool Touching();
	static Finger GetFinger();
private:
	static Touch* Instance();
	static Touch* touchInstance;
	bool isTouching;
	bool isMoving;
	Touch();
	~Touch();
	static void SetEvent(SDL_Event* e);
};

