#pragma once
#include "EngineGlobal.h"

#include <list>
#include <vector>
#include "Scene.h"

#include "Sprite.h"
#include "AudioPool.h"

using namespace std;
using namespace AGameEngine;

class Application
{
public:
	bool isRunning;
	string name;
	Vector2D screenSize;

	Application(void);
	virtual ~Application(void);
	int Run();
	void AddScene(Scene);


private:

	SDL_Renderer *renderer;
	SDL_Window *win;
	list<GameObject*> currentSceneObjects;

	int Init();
	
	void CheckInputs();
	
	void Update();
	void Draw();
	void LoadScene(int loadedScene);
	void UnloadScene();
protected:
	vector<Scene> scenes;	
	int currentScene;
	//TODO Vou adicionar uma lista aki
};

