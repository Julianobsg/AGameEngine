#pragma once
#include "GameObject.h"
#include "Graphics2D.h"

class Sprite :
	public GameObject
{
public:
	Graphics2D texture;
		
	void SetTexture(string textureFile);

	virtual void Update() override;
};

