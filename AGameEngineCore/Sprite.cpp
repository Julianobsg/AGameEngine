#include "Sprite.h"




void Sprite::SetTexture(string textureFile)
{
	this->texturePath = "Media/" + textureFile;
}

void Sprite::Init(SDL_Renderer* renderer)
{
	texture.LoadTexture(this->texturePath, renderer);
}

void Sprite::Update()
{

}

void Sprite::Draw()
{
	Vector2D position;
	position.x = 0;
	position.y = 0;
	texture.Draw(position);
}

