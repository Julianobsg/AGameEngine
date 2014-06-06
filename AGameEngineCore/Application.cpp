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
    
    return 0;
}

int Application::Run()
{
    
    if (Init()) {
        return 1;
    }
    
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

}

void Application::Draw()
{
    list<GameObject*> sceneObjects = scenes[currentScene].gameObjects;

    SDL_RenderClear(renderer);
    
    //Add draw code here...
    
    SDL_RenderPresent(renderer);
}
