#pragma once
#include <string>
#include "Vector2D.h"
#include "EngineGlobal.h"
using namespace std;


class Texture
{
public:
	Texture(void);
	~Texture(void);
	void LoadTexture(string texturePath, SDL_Renderer* renderer);
	void Draw(Vector2D position);
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
};

