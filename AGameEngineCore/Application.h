#pragma once
#include "EngineGlobal.h"

#include <list>
#include <vector>
#include "Scene.h"
using namespace std;

class Application
{
public:
	bool isRunning;
	
	Application(void);
	~Application(void);
	void Run();
	void AddScene(Scene);

	void Update();
	virtual void Draw(GameObject);
protected:
	vector<Scene> scenes;	
	int currentScene;
	//TODO Vou adicionar uma lista aki
};

