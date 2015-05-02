#pragma once
#include "Input.h"
#include "EngineGlobal.h"
#include "Vector2D.h"
#include "Finger.h"
#include <map>

class Touch :
	public Input
{
	friend class Application;
public:
	static bool Touching();
	static Finger* GetFinger(int index);
private:
	static Touch* Instance();
	static Touch* touchInstance;
	bool isTouching;
	bool isMoving;
	std::map<int, Finger*> fingers;
	Touch();
	~Touch();
	static void SetEvent(SDL_Event* e);
	void AddFinger(SDL_TouchFingerEvent e);
	void MoveFinger(SDL_TouchFingerEvent e);
	void RemoveFinger(SDL_TouchFingerEvent e);
};

