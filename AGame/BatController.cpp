//
//  BatController.cpp
//  AGameEngine
//
//  Created by Juliano-Mac on 21/10/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "BatController.h"

BatController::BatController(void)
{
}

void BatController::Update()
{
	if (Keyboard::KeyDown(KeyCode::down))
	{
		transform->position.y +=1;
	} else if (Keyboard::KeyDown(KeyCode::up))
	{
		//  flyingSound.Play();
		transform->position.y -=1;
	}
}

void BatController::Init()
{
	//flyingSound = AGameEngine::Audio("flapping.wav");
}

BatController::~BatController(void)
{
    
}
