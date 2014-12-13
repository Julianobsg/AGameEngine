#include "Sprite.h"

Sprite::Sprite() : GameObject ()
{
    animationPlaying = 0;
}

void Sprite::AddAnimantion(Animation* animation)
{
    animations.push_back(animation);
}

void Sprite::AddTexture(string texturePath)
{
    if (animations.size() == 0) {
        animations.push_back(new Animation);
    }
    
    animations[animations.size() - 1]->AddTexture(texturePath);
}

void Sprite::Init(SDL_Renderer* renderer)
{
    for (int i = 0; i < animations.size(); i++) {
        animations[i]->Init(renderer);
    }
	
	GameObject::Init();
}

void Sprite::Draw()
{
	Texture* texture = animations[animationPlaying]->ActualTexture();
	texture->Draw(this->transform);
}

void Sprite::Destroy()
{
    for (int i = 0; i < animations.size(); i++) {
        animations[i]->Destroy();
    }
}

void Sprite::AddBehaviour(Behaviour* behaviour)
{
	behaviour->texture = LastTexture();
	GameObject::AddBehaviour(behaviour);
}

Texture* Sprite::LastTexture()
{
	return animations[animations.size() - 1]->textures.back();
}

void Sprite::AddClip(int x, int y, int w, int h)
{
	Texture* lastTexture = LastTexture();
	if (lastTexture != NULL)
	{
		Texture* texture = new Texture;
		texture->Copy(lastTexture);
		texture->Clip(x, y, w, h);

		animations[animations.size() - 1]->AddTexture(texture);
	}
}

void Sprite::Play (int animationID)
{
    this->animationPlaying = animationID;
}

