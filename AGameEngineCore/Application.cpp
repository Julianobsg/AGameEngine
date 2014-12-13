#include "Application.h"
#include "Timer.h"
#include <string>
#include "Debug.h"
#include "Keyboard.h"
#include "AudioPool.h"
#include "Touch.h"


Application::Application(void)
{
	currentScene = 0;
	isRunning = true;
	name = "A Game Engine - Game";
	screenSize.x = 640;
	screenSize.y = 480;
}


Application::~Application(void)
{
}

int Application::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		Debug::Log("SDL_Init Error: " + string(SDL_GetError()) + + "\n");
		return 1;
	}
	
	win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenSize.x, screenSize.y,
									   SDL_WINDOW_SHOWN);
	if (win == NULL){
		Debug::Log("SDL_CreateWindow Error: " + string(SDL_GetError()) + + "\n");
		return 1;
	}
	renderer = SDL_CreateRenderer(win, -1,
								  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL){
		renderer = SDL_GetRenderer(win);
	}
	
	if (renderer == NULL){
		Debug::Log("SDL_CreateRenderer Error: " + string(SDL_GetError()) + "\n");
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		Debug::Log("IMG_Init"  + string(SDL_GetError()) + + "\n");
		return 1;
	}
    if (TTF_Init() != 0){
        Debug::Log("TTF_Init" + string(SDL_GetError()) + + "\n");
        return 1;
    }

	mainCamera = new Camera(screenSize);
	Timer::Init();
	AudioPool::Init();
	return 0;
}

int Application::Run()
{
	
	if (Init()) {
		return 1;
	}
	
	LoadScene(0);

	while (isRunning){
		Timer::CalcFPS();

		CheckInputs();
		//Render the scene
		Draw();
		
		Update();
	}

	UnloadScene();

	free(mainCamera);
	AudioPool::Destroy();
	SDL_DestroyRenderer(renderer);
    
	SDL_DestroyWindow(win);
	IMG_Quit();
	SDL_Quit();
	return 0;
}

void Application::AddScene(Scene scene)
{
	scenes.push_back(scene);
}

void Application::CheckInputs()
{
	SDL_Event e;

	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT)
			isRunning = false;
		Keyboard::SetKeyDown(&e);
		Touch::SetTouch(&e);
	}
	
}

void Application::Update()
{
	GameObject* go;

	for (std::list<GameObject*>::iterator it = currentSceneObjects.begin(); it != currentSceneObjects.end(); it++)
	{
		go = *it;
		go->Update();
	}
}

void Application::Draw()
{

	SDL_RenderClear(renderer);
	
	GameObject* go;

	for (std::list<GameObject*>::iterator it = currentSceneObjects.begin(); it != currentSceneObjects.end(); it++)
	{
		go = *it;
		Sprite* sprite = dynamic_cast<Sprite*>(go);
		if (sprite != NULL)
		{
			mainCamera->Draw(sprite);
		}
	}
	SDL_RenderPresent(renderer);
}

void Application::LoadScene(int loadedScene)
{
	this->currentScene = loadedScene;

	currentSceneObjects = scenes[currentScene].gameObjects;

	GameObject* go;

	for (std::list<GameObject*>::iterator it = currentSceneObjects.begin(); it != currentSceneObjects.end(); it++)
	{
		go = *it;
		Sprite* sprite = dynamic_cast<Sprite*>(go);
		if (sprite != NULL)
		{
			sprite->Init(renderer);
		} else
		{
			go->Init();
		}
	}
}

void Application::UnloadScene()
{
	GameObject* go;

	for (std::list<GameObject*>::iterator it = currentSceneObjects.begin(); it != currentSceneObjects.end(); it++)
	{
		go = *it;
		Sprite* sprite = dynamic_cast<Sprite*>(go);
		if (sprite != NULL)
		{
			sprite->Destroy();
		}
	}
}
