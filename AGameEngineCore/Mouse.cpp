//
//  Mouse.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 04/02/15.
//  Copyright (c) 2015 AGameEngine. All rights reserved.
//

#include "Mouse.h"


Mouse* Mouse::mouseInstance;

void Mouse::SetEvent(SDL_Event* e)
{

	if (e->type == SDL_MOUSEMOTION)
	{
		Instance()->position->SetVector(e->motion.x, e->motion.y);
	}
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		Instance()->buttonPressed = static_cast<MouseCode> (e->button.button);
	} else if (e->type == SDL_MOUSEBUTTONUP)
	{
		Instance()->buttonPressed = MouseCode::none;
	}
	else
	{
		Instance()->buttonPressed = MouseCode::none;
	}
	if (e->type == SDL_MOUSEWHEEL)
	{
	}
}

Vector2D<int>* Mouse::Position()
{
	return Instance()->position;
}

Mouse::Mouse()
{
	position = new Vector2D<int>();
}

Mouse::~Mouse()
{

}

Mouse* Mouse::Instance()
{
	if (!mouseInstance)
	{
		mouseInstance = new Mouse;
	}
	return mouseInstance;
}

bool Mouse::MouseButtonDown(MouseCode mouseButton)
{
	return mouseButton == Instance()->buttonPressed;
}
