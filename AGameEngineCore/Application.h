#pragma once
#include "EngineGlobal.h"

#include <list>
#include <vector>
#include "Scene.h"

#include "Sprite.h"
#include "Text.h"
#include "AudioPool.h"
#include "Camera.h"

using namespace std;
using namespace AGameEngine;

class Application
{
public:
	bool isRunning;
	string name;

	Application(void);
	Camera* mainCamera;
	virtual ~Application(void);
	int Run();
	void AddScene(Scene);
	void SetScreenSize(Vector2D<int> size);

private:
	Vector2D<int> screenSize;

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

