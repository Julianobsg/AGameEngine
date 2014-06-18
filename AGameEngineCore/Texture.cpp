#include "Texture.h"


Texture::Texture(void)
{
}


Texture::~Texture(void)
{
}

void Texture::LoadTexture(string texturePath, SDL_Renderer* renderer)
{
	this->renderer = renderer;
	
	const char * c = texturePath.c_str();

	texture = IMG_LoadTexture(renderer,c);
	if (!texture) {
		fprintf(stderr, "Couldn't load %s: %s\n", c, SDL_GetError());
	}
}

void Texture::Draw(Vector2D position)
{
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	SDL_Rect dst;
	dst.x = position.x;
	dst.y = position.y;
	//TODO then maybe put a scale factor here, for resizing image
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}
