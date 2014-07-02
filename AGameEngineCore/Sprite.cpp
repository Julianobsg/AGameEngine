#include "Sprite.h"

void Sprite::AddTexture(string textureFile)
{
	if (animations == nullptr)
	{
		animations = new Animation;
	}
	Texture* texture = new Texture();
	texture->texturePath = "Media/" + textureFile;

	animations->AddTexture(texture);
}

void Sprite::Init(SDL_Renderer* renderer)
{
	animations->Init(renderer);
	
	GameObject::Init();
}

void Sprite::Draw()
{
	animations->Draw(transform);
}

void Sprite::Destroy()
{
	animations->Destroy();
}

void Sprite::AddBehaviour(Behaviour* behaviour)
{
	behaviour->texture = LastTexture();
	GameObject::AddBehaviour(behaviour);
}

Texture* Sprite::LastTexture()
{
	return animations->textures.back();
}

void Sprite::AddClip(int x, int y, int w, int h)
{
	Texture* lastTexture = LastTexture();
	if (lastTexture != NULL)
	{
		Texture* texture = new Texture;
		texture->Copy(lastTexture);
		texture->Clip(x, y, w, h);

		animations->AddTexture(texture);
	}
}

