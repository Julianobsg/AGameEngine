#pragma once
#include "Scene.h"

class EndGameScene :
	public Scene
{
public:
	int score;
	EndGameScene();
	~EndGameScene();
	void Init();

private:
	void LoadGameplay();
	void LoadMainMenu();

};

