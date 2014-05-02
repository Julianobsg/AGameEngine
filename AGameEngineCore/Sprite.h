#pragma once
#include "GameObject.h"

class Sprite :
	public GameObject
{
public:
	string texture;
		
	void SetTexture(string textureFile);

	virtual void Update() override;
};

