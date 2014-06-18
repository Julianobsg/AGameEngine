#pragma once
#include "EngineGlobal.h"

#include <list>
#include <vector>
#include "Scene.h"

#include <iostream>
#include "Sprite.h"

using namespace std;

class Application
{
public:
	bool isRunning;
	
	Application(void);
	virtual ~Application(void);
	int Run();
	void AddScene(Scene);


private:

	SDL_Renderer *renderer;
	SDL_Window *win;
		
	int Init();
	
	void CheckInputs();
	
	void Update();
	void Draw();
	void LoadScene(int loadedScene);

protected:
	vector<Scene> scenes;	
	int currentScene;
	//TODO Vou adicionar uma lista aki
};

