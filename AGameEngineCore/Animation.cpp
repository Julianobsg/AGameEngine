
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

Texture* Animation::ActualFrame()
{
	Texture* texture = textures[actualFrame];

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

	return texture;
}

void Animation::Destroy()
{
	for (vector<Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
	{
		(*it)->Destroy();
	}
}

void Animation::AddClip(int x, int y, int w, int h)
{
	if (clipped)
	{
		Texture* texture = new Texture;
		texture->Copy(textures.back());
		texture->Clip(x, y, w, h);
		textures.push_back(texture);
	}
	else
	{
		this->Clip(x, y, w, h);
		this->clipped = true;
	}
}

void Animation::Clip(int x, int y, int w, int h)
{
	Texture* texture = textures.back();
	texture->Clip(x, y, w, h);
}

Texture* Animation::LastTexture()
{
	Texture* texture = new Texture;
	texture->Copy(textures.back());
	return texture;
}
