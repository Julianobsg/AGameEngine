#include "Texture.h"
#include "Transform.h"
#include "Debug.h"


Texture::Texture(void)
{
	clip = NULL;
}


Texture::~Texture(void)
{
}

void Texture::LoadTexture(string texturePath, SDL_Renderer* renderer)
{
	this->renderer = renderer;
	
#ifdef _WIN32
	texturePath = "Media/" + texturePath;
#endif
	const char * c = texturePath.c_str();
	SDL_Texture* texture = IMG_LoadTexture(renderer,c);
	if (!texture) {
		fprintf(stderr, "Couldn't load %s: %s\n", c, SDL_GetError());
	}

	LoadTexture(texture);
}

void Texture::LoadTexture(SDL_Renderer* renderer)
{
	LoadTexture(this->texturePath, renderer);
}

void Texture::LoadTexture(SDL_Texture* texture)
{
	this->texture = texture;

	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
}

void Texture::LoadTexture(SDL_Texture* texture, SDL_Renderer* renderer)
{
	this->renderer = renderer;

}

void Texture::Draw(Transform* transform)
{
	Vector2D<float>* position = &transform->position;
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL , &w, &h);

	SDL_Rect dst;
	dst.x = position->x;
	dst.y = position->y;

	SDL_RendererFlip isFlipping = CheckImageScale(transform);


	Vector2D<float> scale = transform->scale;
    
    scale = scale.Abs();
	//TODO then maybe put a scale factor here, for resizing image
	if (clip != NULL){
		dst.w = clip->w * scale.x;
		dst.h = clip->h * scale.y;
	}
	else
	{
		dst.w = size.x * scale.x;
		dst.h = size.y * scale.y;
	}

	SDL_RenderCopyEx(renderer, texture, clip, &dst, transform->angle, NULL, isFlipping);
}


void Texture::Clip (int x, int y, int w, int h)
{
	SDL_Rect rect = {x, y, w, h};
	clip = new SDL_Rect(rect);

	size.x = w - x;
	size.y = h - y;
}

void Texture::Destroy()
{
	SDL_DestroyTexture(texture);
}

SDL_RendererFlip Texture::CheckImageScale(Transform* transform)
{
	SDL_RendererFlip isFlipping = SDL_FLIP_NONE;

	Vector2D<float>* scale = &transform->scale;
	if (scale->x < 0 && scale->y < 0)
	{
		isFlipping = ((SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL));
	} else if (scale->x < 0)
	{
		isFlipping = SDL_FLIP_HORIZONTAL;
	} else if (scale->y < 0)
	{
		isFlipping = SDL_FLIP_VERTICAL;
	}		

	return isFlipping;
}

void Texture::Copy(Texture* originalTexture)
{
	this->texture = originalTexture->texture;
	this->texturePath = originalTexture->texturePath;
	this->renderer = originalTexture->renderer;
}
