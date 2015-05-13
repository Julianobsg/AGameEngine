#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();
	void LoadLevel();
	void QuitGame();
};

