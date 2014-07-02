#pragma once
#include "Texture.h"
#include <vector>

using namespace std;

class Animation
{
public:
	int framesPerSecond;
	vector<Texture*> textures;
	int actualFrame;

	Animation(void);
	~Animation(void);
	
	void AddTexture(Texture* texture);
	void Init(SDL_Renderer* renderer);
	void Draw(Transform* transform);
	void Destroy();
private:
	int framesCounter;
	int gamefps;
};

