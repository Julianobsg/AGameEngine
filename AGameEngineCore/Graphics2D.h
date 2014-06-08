#pragma once
#include <string>
#include "SDL_Image\SDL_image.h"

using namespace std;

class Graphics2D
{
public:
	Graphics2D(void);
	~Graphics2D(void);
	void LoadTexture(string texturePath, SDL_Renderer* renderer);
	void Draw();
};

