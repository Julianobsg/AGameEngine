#pragma once
#include "GameObject.h"
#include "Texture.h"

class Sprite :
	public GameObject
{
public:
	Texture texture;
		
	void SetTexture(string textureFile);
	virtual void Update() override;
	void Init(SDL_Renderer* renderer);

	void Draw();
private:
	string texturePath;
};

