#pragma once
#include "Scene.h"
#include "Text.h"
#include "UIButton.h"

class MainMenu : public Scene
{
public:

	MainMenu();
	~MainMenu();
	void LoadLevel();
	void QuitGame();

	void Init();

private:
	Text* header;
	UIButton* playButton;
	UIButton* quitButton;
};

