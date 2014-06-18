#include "Application.h"
#include <thread>         // std::thread


Application::Application(void)
{
	currentScene = 0;
	isRunning = true;
}


Application::~Application(void)
{
}

int Application::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480,
									   SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	renderer = SDL_CreateRenderer(win, -1,
								  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		renderer = SDL_GetRenderer(win);
	}
	
	if (renderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
	//	std::cout << "IMG_Init"  << SDL_GetError() << std::endl;
	//	return 1;
	//}

	return 0;
}

int Application::Run()
{
	
	if (Init()) {
		return 1;
	}
	
	LoadScene(0);

	while (isRunning){
		CheckInputs();
		//Render the scene
		Draw();
		
		Update();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
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
		if (e.type == SDL_KEYDOWN)
			isRunning = false;
		if (e.type == SDL_MOUSEBUTTONDOWN)
			isRunning = false;
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
			sprite->Draw();
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
