#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Animation.h"

class Sprite :
	public GameObject
{
public:
	Animation* animations;
		
	void AddTexture(string textureFile);
	void AddClip (int x, int y, int w, int h);
	void Init(SDL_Renderer* renderer);
	void Draw();
	void Destroy();

	virtual void AddBehaviour(Behaviour* behaviour);
	Texture* LastTexture();
};

