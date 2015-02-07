#pragma once
#include "Input.h"
#include "EngineGlobal.h"
class Touch :
	public Input
{
	friend class Application;
public:
	static bool isTouching;
	Touch();
	~Touch();
private:
	static void SetEvent(SDL_Event* e);
};

