#include "Graphics2D.h"


Graphics2D::Graphics2D(void)
{
}


Graphics2D::~Graphics2D(void)
{
}

void Graphics2D::LoadTexture(string texturePath, SDL_Renderer* renderer)
{
	const char * c = texturePath.c_str();

	SDL_Texture* texture = IMG_LoadTexture(renderer,c);
	if (!texture) {
		fprintf(stderr, "Couldn't load %s: %s\n", c, SDL_GetError());
	}
}

void Graphics2D::Draw()
{
}
