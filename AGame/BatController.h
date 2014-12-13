//
//  BatController.h
//  AGameEngine
//
//  Created by Juliano-Mac on 21/10/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __AGameEngine__BatController__
#define __AGameEngine__BatController__

#include <iostream>

#endif /* defined(__AGameEngine__BatController__) */

#include "Behaviour.h"
#include "Audio.h"
#include "Keyboard.h"


class BatController : public Behaviour
{
public:
	AGameEngine::Audio flyingSound;
	
	BatController(void);
	~BatController(void);
    
	void Update();
    
	void Init();
    
};

