#include "Application.h"
#include "Timer.h"
#include <string>
#include "Debug.h"
#include "Keyboard.h"
#include "AudioPool.h"
#include "Touch.h"
#include "Mouse.h"


Application::Application(void)
{
	currentScene = 0;
	isRunning = true;
	name = "A Game Engine - Game";
	screenSize.x = 640;
	screenSize.y = 480;
	mainCamera = new Camera(screenSize);
	this->application = this;
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

	Timer::Init();
	AudioPool::Init();
	return 0;
}

int Application::Run()
{
	return Instance()->_Run();
}

void Application::AddScene(Scene scene)
{
	Instance()->_AddScene(scene);
}

void Application::_AddScene(Scene scene)
{
	scenes.push_back(scene);
}

void Application::CheckInputs()
{
	SDL_Event e;

	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT)
			isRunning = false;
		Keyboard::SetEvent(&e);
		Touch::SetEvent(&e);
		Mouse::SetEvent(&e);
	}
	
}

void Application::Update()
{
	scenes[currentScene].Update();
}

void Application::Draw()
{

	SDL_RenderClear(renderer);
	scenes[currentScene].Draw(mainCamera);

	SDL_RenderPresent(renderer);
}

void Application::_LoadScene(int loadedScene)
{
	this->currentScene = loadedScene;

	this->scenes[currentScene].Load(renderer);
}

void Application::LoadScene(string loadSceneName)
{
	
	for (int i = 0; i < application->scenes.size(); i++)
	{
		if (application->scenes[i].name == loadSceneName)
		{
			application->_LoadScene(i);
			return;
		}
	}
}

void Application::LoadScene(int loadSceneId)
{
	application->_LoadScene(loadSceneId);
}

//TODO check memory freeing here
void Application::UnloadScene()
{
	this->scenes[currentScene].Unload();
}

void Application::SetScreenSize(Vector2D<int> size)
{
	Instance()->_SetScreenSize(size);
}

void Application::_SetScreenSize(Vector2D<int> size)
{
	this->screenSize = size;
	mainCamera->SetScreenSize(this->screenSize);
}

Application* Application::Instance()
{
	if (application == NULL)
	{
		application = new Application();
	}
	return application;
}

int Application::_Run()
{

	if (Init()) {
		return 1;
	}

	_LoadScene(0);

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
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}


void Application::SetMainCamera(Camera* mainCamera)
{
	Instance()->mainCamera = mainCamera;
}

void Application::SetGameName(string name)
{
	Instance()->name = name;
}

Vector2D<int> Application::GetScreenSize()
{
	return Instance()->screenSize;
}

void Application::CloseGame()
{
	Instance()->isRunning = false;
}

Camera* Application::GetMainCamera()
{
	return Instance()->mainCamera;
}

Application* Application::application;
