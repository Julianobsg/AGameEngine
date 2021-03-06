//
//  GamePlayScene.h
//  AGameEngine
//
//  Created by Juliano-Mac on 18/09/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __AGameEngine__GamePlayScene__
#define __AGameEngine__GamePlayScene__

#include <iostream>
#include "Scene.h"
#include "Animation.h"
#include "Sprite.h"
#include "Text.h"
#endif /* defined(__AGameEngine__GamePlayer__) */

class GamePlayScene : public Scene
{ 
public:
	GamePlayScene();
    virtual void Init();
private:
	void InitializeUI();
};