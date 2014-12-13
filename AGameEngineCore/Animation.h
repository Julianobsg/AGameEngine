#pragma once
#include "Texture.h"
#include <vector>
#include "Debug.h"
#include "Timer.h"

using namespace std;

class Animation
{
public:
	int framesPerSecond;
	vector<Texture*> textures;
	int actualFrame;

	Animation(void);
	~Animation(void);
	
	void AddTexture(string texturePath);
    void AddTexture(Texture* texture);
	void Init(SDL_Renderer* renderer);
	Texture* ActualTexture();
	void Destroy();
private:
	int framesCounter;
	int gamefps;
};

