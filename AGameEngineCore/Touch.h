#pragma once
#include "Input.h"
#include "EngineGlobal.h"
class Touch :
	public Input
{
public:
	static bool isTouching;
	Touch();
	~Touch();
	static void SetTouch(SDL_Event* e);
};

