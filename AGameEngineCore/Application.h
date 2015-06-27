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
	static void SetMainCamera(Camera* mainCamera);
	static Camera* GetMainCamera();
	static void SetGameName(string name);
	static void CloseGame();
	static int Run();
	static void AddScene(Scene*);
	static void SetScreenSize(Vector2D<int> size);

	static void LoadScene(string sceneName);
	static void LoadScene(int loadSceneId);
	static Scene* GetScene(string loadSceneName);
	static Scene* GetScene(int sceneId);
	static Vector2D<int> GetScreenSize();
	static int GetSceneIdByName(string sceneName);
private:
	static Application* Instance();
	bool isRunning;
	string name;
	int newScene;

	Application(void);
	Camera* mainCamera;
	virtual ~Application(void);
	int _Run();
	void _AddScene(Scene*);
	void _SetScreenSize(Vector2D<int> size);

	static Application* application;

	Vector2D<int> screenSize;

	SDL_Renderer *renderer;
	SDL_Window *win;

	int Init();
	
	void CheckInputs();
	
	void Update();
	void Draw();
	void _LoadScene(int loadedScene);
	Scene* _GetScene(int sceneId);
	void UnloadScene();
protected:
	vector<Scene*> scenes;	
	int currentScene;
	//TODO Vou adicionar uma lista aki
};

