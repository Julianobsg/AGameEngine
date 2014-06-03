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


int Application::Run()
{
	list<GameObject*> sceneObjects = scenes[currentScene].gameObjects;

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
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Event e;
	while (isRunning){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT)
				isRunning = false;
			if (e.type == SDL_KEYDOWN)
				isRunning = false;
			if (e.type == SDL_MOUSEBUTTONDOWN)
				isRunning = false;
		}
		//Render the scene
		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

void Application::AddScene(Scene scene)
{
	scenes.push_back(scene);
}

void Application::Update()
{

}

void Application::Draw(GameObject go)
{
	printf("%s", go.name);
}
