#pragma once
#include "EngineGlobal.h"

#include <list>
#include <vector>
#include "Scene.h"
#include <SDL.h>
#include <iostream>

using namespace std;

class Application
{
public:
	bool isRunning;
	
	Application(void);
	virtual ~Application(void);
	int Run();
	void AddScene(Scene);

	void Update();
	void Draw(GameObject);
protected:
	vector<Scene> scenes;	
	int currentScene;
	//TODO Vou adicionar uma lista aki
};

