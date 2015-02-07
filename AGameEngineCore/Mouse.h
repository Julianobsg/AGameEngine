//
//  Mouse.h
//  AGameEngine
//
//  Created by Juliano-Mac on 04/02/15.
//  Copyright (c) 2015 AGameEngine. All rights reserved.
//

#pragma once

#include "EngineGlobal.h"
#include "Input.h"
#include "input.h"
#include "Vector2D.h"


enum class MouseCode
{
	none = 0,
	left = SDL_BUTTON_LEFT,
	right = SDL_BUTTON_RIGHT,
	middle = SDL_BUTTON_MIDDLE,
};

class Mouse : public Input
{
	friend class Application;
public:

	static Vector2D<int>* Position();
	static bool MouseButtonDown(MouseCode mouseButton);
	static Mouse* Instance();
private:
	static Mouse* mouseInstance;
	
	MouseCode buttonPressed;
	Mouse();
	~Mouse();
	Vector2D<int>* position;
	static void SetEvent(SDL_Event* e);
};