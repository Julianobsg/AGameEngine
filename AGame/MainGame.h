#pragma once
#include "stdafx.h"

#include "Application.h"
#include "Scene.h"
#include "Sprite.h"

class MainGame
{
public:
	MainGame(Application*);
	~MainGame(void);

	void Init();
private:
	Application* application;
};

