
#include "Animation.h"

Animation::Animation(void)
{
	actualFrame = 0;
	framesPerSecond = 12;
	framesCounter = 0;

}


Animation::~Animation(void)
{
}

void Animation::AddTexture(string texturePath)
{
    Texture* texture = new Texture;
    texture->texturePath = texturePath;
    AddTexture(texture);
}

void Animation::AddTexture(Texture* texture)
{
    if (texture != NULL)
    {
        textures.push_back(texture);
    }
}

void Animation::Init(SDL_Renderer* renderer)
{
	for (vector<Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
	{
		(*it)->LoadTexture(renderer);
	}
	gamefps = Timer::framesPerSecond;
}

void Animation::Draw(Transform* transform)
{
	Texture* texture = textures[actualFrame];
	texture->Draw(transform);

	framesCounter++;

	if (framesCounter == (gamefps / framesPerSecond))
	{
		framesCounter = 0;
		actualFrame++;
	}

	
	if (actualFrame >= textures.size())
	{
		actualFrame = 0;
	}
}

void Animation::Destroy()
{
	for (vector<Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
	{
		(*it)->Destroy();
	}
}
