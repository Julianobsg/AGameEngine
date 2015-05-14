#include "Sprite.h"
#define DEFAULT_PIXELS_PER_METER 50

Sprite::Sprite() : GameObject ()
{
    animationPlaying = 0;
    pixelsPerMeter = DEFAULT_PIXELS_PER_METER;
	clipped = false;
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
    
    animations.back()->AddTexture(texturePath);
}

void Sprite::Load(SDL_Renderer* renderer)
{
    for (int i = 0; i < animations.size(); i++) {
        animations[i]->Init(renderer);
    }
}

void Sprite::Draw(Transform* cameraTransform)
{
	Texture* texture = animations[animationPlaying]->ActualFrame();

	Vector2D<float> scale = Vector2D<float>(cameraTransform->scale.x / pixelsPerMeter,
		cameraTransform->scale.y / pixelsPerMeter);
	cameraTransform->scale = scale;
	texture->Draw(cameraTransform);
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

	Animation* actualAnimation = animations.back();
	actualAnimation->AddClip(x, y, w, h);
		
}

void Sprite::Play (int animationID)
{
    this->animationPlaying = animationID;
}

