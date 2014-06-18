#include "Sprite.h"


void Sprite::SetTexture(string textureFile)
{
	this->texturePath = "Media/" + textureFile;
}

void Sprite::Init(SDL_Renderer* renderer)
{
	texture.LoadTexture(this->texturePath, renderer);
	GameObject::Init();
}

void Sprite::Draw()
{
	texture.Draw(transform->position);
}


