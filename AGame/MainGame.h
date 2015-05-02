#pragma once
#include "stdafx.h"

#include "Application.h"
#include "Scene.h"
#include "Sprite.h"

#include "GamePlayScene.h"
class MainGame
{
public:
	MainGame(void);
	~MainGame(void);

	void Init();
	int Run();
};

